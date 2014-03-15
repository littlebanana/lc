// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
//  Given linked list: 1->2->3->4->5, and n = 2.
//  After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
//  Given n will always be valid.
//  Try to do this in one pass. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;

            ListNode *tp = dummy;
            ListNode *t = head;
            ListNode *tn = head;
            while (tn != NULL)
            {
                if (n > 0)
                {
                    n--;
                    tn = tn->next;
                }
                else
                {
                    tp = t;
                    t = t->next;
                    tn = tn->next;
                }
            }

            // t points to the node to be deleted
            tp->next = t->next;
            delete t;

            head = dummy->next;
            delete dummy;
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
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);

    printList(l);

    Solution solu;
    l = solu.removeNthFromEnd(l, 2);
    printList(l);

    l = solu.removeNthFromEnd(l, 1);
    printList(l);

    l = solu.removeNthFromEnd(l, 3);
    printList(l);

    destroyList(l);

    return 0;
}
