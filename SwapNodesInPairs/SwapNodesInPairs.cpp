// Given a linked list, swap every two adjacent nodes and return its head.
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Your algorithm should use only constant space.
// You may not modify the values in the list, only nodes itself can be changed. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        // swap the two nodes after head, and return the tail
        // For example, if the list is 1->2->3->..., and the head is the pointer to 1
        // after the swap, the list is 1->3->2->...
        // and return the pointer to 2
        ListNode *swapNode(ListNode *head)
        {
            if (head == NULL || head->next == NULL || head->next->next == NULL)
            {
                return NULL;
            }

            // swap head->next and head->next->next
            ListNode *t1 = head->next;
            ListNode *t2 = head->next->next;

            head->next = t2;
            t1->next = t2->next;
            t2->next = t1;

            return t1;
        }

        ListNode *swapPairs(ListNode *head) {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;

            ListNode *t = dummy;
            while (t != NULL)
            {
                t = swapNode(t);
            }

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
    l = solu.swapPairs(l);

    printList(l);

    destroyList(l);

    return 0;
}
