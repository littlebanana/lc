// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// Follow up:
// Can you solve it without using extra space? 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *fast = head;
            ListNode *slow = NULL;
            while (fast != NULL && fast != slow)
            {
                if (fast->next == NULL)
                {
                    return NULL;
                }
                fast = fast->next->next;
                slow = (slow == NULL ? head->next : slow->next);
            }
            if (fast == NULL)
            {
                return NULL;
            }
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
};

void destroyList(ListNode *head, ListNode *node)
{
    bool first = false;
    while (head != NULL)
    {
        ListNode *tbd = head;
        if (head == node)
        {
            first = true;
        }
        head = head->next;
        if (first && head == node)
        {
           break; 
        }
        delete tbd;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next;

    Solution solu;
    ListNode *node = solu.detectCycle(head);
    if (node == NULL)
    {
        cout << "no cycle" << endl;
    }
    else
    {
        cout << node->val << endl;
    }

    destroyList(head, node);

    return 0;
}
