// Given a list, rotate the list to the right by k places, where k is non-negative.
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == NULL || k == 0)
            {
                return head;
            }

            // record the number of nodes
            // record the pointer to the tail node
            int n = 1;
            ListNode *oldtail = head;
            while (oldtail->next != NULL)
            {
                n++;
                oldtail = oldtail->next;
            }

            // skip a full loop, only need the modulus
            k %= n;
            if (k == 0)
            {
                return head;
            }

            // # of elements to cut in the front
            k = n - k;

            // record the pointer to the new tail node
            int cnt = 1;
            ListNode *newtail = head;
            while (cnt < k)
            {
                cnt++;
                newtail = newtail->next;
            }

            ListNode *newhead = newtail->next;
            newtail->next = NULL;
            oldtail->next = head;
            return newhead;
        }
};

void printList(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

void destroyList(ListNode *l)
{
    while (l != NULL)
    {
        ListNode *tbd = l;
        l = l->next;
        delete tbd;
    }
}

int main()
{
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);

    printList(l);

    Solution solu;
    l = solu.rotateRight(l, 1);

    printList(l);

    destroyList(l);

    return 0;
}
