// Given a singly linked list L: L0->L1->...->Ln-1->Ln, reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
// You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void reorderList(ListNode *head) {
            // count the length of the list
            int n = 0;
            ListNode *t = head;
            while (t != NULL)
            {
                n++;
                t = t->next;
            }
            if (n < 3)
            {
                return;
            }

            // cut the list into two
            int m = (n+1)/2;
            int cnt = 1;
            t = head;
            while (cnt < m)
            {
                cnt++;
                t = t->next;
            }
            ListNode *head2 = t->next;
            t->next = NULL; 

            // reverse the second list
            ListNode *tp = head2;
            t = head2->next;
            while (t != NULL)
            {
                ListNode *tn = t->next;
                t->next = tp;
                tp = t;
                t = tn;
            }
            head2->next = NULL;
            head2 = tp;

            // interleave two lists
            t = head;
            ListNode *p = head->next;
            ListNode *q = head2;
            bool one = false;
            while (p != NULL && q != NULL)
            {
                if (one)
                {
                    t->next = p;
                    p = p->next;
                    t = t->next;
                }
                else
                {
                    t->next = q;
                    q = q->next;
                    t = t->next;
                }
                one = !one;
            }
            t->next = (p == NULL ? q : p);
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
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(6);
    l1->next->next->next->next->next->next = new ListNode(7);
    printList(l1);

    Solution solu;
    solu.reorderList(l1);
    printList(l1);

    destroyList(l1);

    return 0;
}
