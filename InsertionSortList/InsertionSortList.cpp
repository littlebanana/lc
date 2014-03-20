// Sort a linked list using insertion sort.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *insertionSortList(ListNode *head) {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode *tp = head;
            ListNode *t = head->next;
            while (t != NULL)
            {
                ListNode *pp = NULL;
                ListNode *p = head;
                while (p != t && t->val >= p->val)
                {
                    pp = p;
                    p = p->next;
                }
                if (p != t)
                {
                    tp->next = t->next;
                    t->next = p;
                    if (pp == NULL)
                    {
                        head = t;
                    }
                    else
                    {
                        pp->next = t;
                    }
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
    printList(l);

    Solution solu;
    l = solu.insertionSortList(l);

    printList(l);
    destroyList(l);

    return 0;
}
