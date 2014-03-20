// Sort a linked list in O(n log n) time using constant space complexity.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        // merge sort lists
        ListNode *merge(ListNode *l1, ListNode *l2)
        {
            if (l1 == NULL)
            {
                return l2;
            }
            if (l2 == NULL)
            {
                return l1;
            }

            ListNode *head = (l1->val < l2->val ? l1 : l2);
            ListNode *p = (l1->val < l2->val ? l1->next : l1);
            ListNode *q = (l1->val < l2->val ? l2 : l2->next);
            ListNode *t = head;
            while (p != NULL && q != NULL)
            {
                if (p->val < q->val)
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
            }
            if (p == NULL)
            {
                p = q;
            }
            t->next = p;
            return head;
        }

        // merge sort
        ListNode *mergeSort(ListNode *l)
        {
            // singleton
            if (l == NULL || l->next == NULL)
            {
                return l;
            }

            // scan the list to find the length
            int n = 0;
            ListNode *t = l;
            while (t != NULL)
            {
                n++;
                t = t->next;
            }

            // cut into two lists
            int m = (n+1)/2;
            ListNode *tail1 = l;
            while (m > 1)
            {
                m--;
                tail1 = tail1->next;
            }

            ListNode *l1 = l;
            ListNode *l2 = tail1->next;
            tail1->next = NULL;
            l1 = mergeSort(l1);
            l2 = mergeSort(l2);
            return merge(l1, l2);
        }

        ListNode *sortList(ListNode *head) {
            return mergeSort(head);
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
    ListNode *l = new ListNode(2);
    l->next = new ListNode(4);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(7);
    l->next->next->next->next = new ListNode(4);
    l->next->next->next->next->next = new ListNode(3);
    l->next->next->next->next->next->next = new ListNode(9);
    l->next->next->next->next->next->next->next = new ListNode(7);
    l->next->next->next->next->next->next->next->next = new ListNode(6);
    l->next->next->next->next->next->next->next->next->next = new ListNode(8);

    Solution solu;
    l = solu.sortList(l);

    printList(l);
    destroyList(l);

    return 0;
}
