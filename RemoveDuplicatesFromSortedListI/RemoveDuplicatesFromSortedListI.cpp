// Given a sorted linked list, delete all duplicates such that each element appear only once.
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode *tp = head;
            ListNode *t = head->next;
            while (t != NULL)
            {
                if (t->val == tp->val)
                {
                    tp->next = t->next;
                    delete t;
                    t = tp->next;
                }
                else
                {
                    tp = t;
                    t = t->next;
                }
            }
            return head;
        }
};

void destroyList(ListNode *l)
{
    while (l != NULL)
    {
        ListNode *tbd = l;
        l = l->next;
        delete tbd;
    }
}

void printList(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val;
        if (l->next != NULL)
        {
            cout << "->";
        }
        l = l->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l = new ListNode(1);
    l->next = new ListNode(1);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(3);
    l->next->next->next->next = new ListNode(3);
    printList(l);

    Solution solu;
    l = solu.deleteDuplicates(l);
    printList(l);

    destroyList(l);

    return 0;
}
