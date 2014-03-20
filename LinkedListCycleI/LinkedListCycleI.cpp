// Given a linked list, determine if it has a cycle in it.
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
        bool hasCycle(ListNode *head) {
            ListNode *fast = head;
            ListNode *slow = NULL;
            while (fast != NULL && fast != slow)
            {
                if (fast->next == NULL)
                {
                    return false;
                }
                fast = fast->next->next;
                slow = (slow == NULL ? head->next : slow->next);
            }
            return (fast != NULL);
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
    cout << (solu.hasCycle(head) ? "has cycle" : "no cycle") << endl;

    return 0;
}
