// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists

#include <iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        
        ListNode *head = (l1->val > l2->val ? l2 : l1);
        ListNode *p = (l1->val > l2->val ? l1 : l1->next);
        ListNode *q = (l1->val > l2->val ? l2->next : l2);
        ListNode *t = head;
        while (p != NULL && q != NULL)
        {
            if (p->val > q->val)
            {
                t->next = q;
                q = q->next;
                t = t->next;
            }
            else
            {
                t->next = p;
                p = p->next;
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
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(9);

    printList(l1);
    printList(l2);

    Solution solu;
    ListNode *merged = solu.mergeTwoLists(l1, l2);

    printList(merged);

    destroyList(merged);

    return 0;
}
