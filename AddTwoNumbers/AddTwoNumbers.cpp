// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *cloneList(ListNode *l)
        {
            ListNode *head = new ListNode(l->val);
            ListNode *t = head;
            l = l->next;
            while (l != NULL)
            {
                t->next = new ListNode(l->val);
                l = l->next;
                t = t->next;
            }
            return head;
        }

        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if (l1 == NULL && l2 == NULL)
            {
                return NULL;
            }
            if (l1 == NULL)
            {
                return cloneList(l2);
            }
            if (l2 == NULL)
            {
                return cloneList(l1);
            }

            int carry = (l1->val+l2->val) / 10;
            ListNode *head = new ListNode((l1->val+l2->val) % 10);
            ListNode *t = head;
            ListNode *p = l1->next;
            ListNode *q = l2->next;
            while (p != NULL && q != NULL)
            {
                int sum = p->val + q->val + carry;
                t->next = new ListNode(sum % 10);
                carry = sum / 10;
                p = p->next;
                q = q->next;
                t = t->next;
            }
            if (p == NULL)
            {
                p = q;
            }
            while (p != NULL)
            {
                int sum = p->val + carry;
                t->next = new ListNode(sum % 10);
                carry = sum / 10;
                p = p->next;
                t = t->next;
            }
            if (carry > 0)      // don't forget the most significant digit
            {
                t->next = new ListNode(carry);
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
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(4);

    Solution solu;
    ListNode *sum = solu.addTwoNumbers(l1, l2);

    printList(l1);
    printList(l2);
    printList(sum);

    destroyList(l1);
    destroyList(l2);
    destroyList(sum);

    return 0;
}
