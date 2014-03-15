// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.
// For example, Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        // reverse the k nodes after the head and return the pointer to the last one
        // make sure there are k nodes after the head before the function call
        ListNode *reverseNodes(ListNode *head, int k)
        {
            if (k == 0 || k == 1)
            {
                return head->next;
            }

            int cnt = 1;
            ListNode *tp = head->next;
            ListNode *t = tp->next;
            while (cnt < k)
            {
                cnt++;
                ListNode *tn = t->next;
                t->next = tp;
                tp = t;
                t = tn;
            }

            ListNode *tail = head->next;
            head->next = tp;
            tail->next = t;
            return tail;
        }

        ListNode *reverseKGroup(ListNode *head, int k) {
            // find the length of the list
            ListNode *t = head;
            int l = 0;
            while (t != NULL)
            {
                l++;
                t = t->next;
            }

            ListNode *dummy = new ListNode(-1);
            dummy->next = head;

            int n = l / k;  // # of groups to be reversed
            t = dummy;
            for (int i = 0; i < n; i++)
            {
                t = reverseNodes(t, k);
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
    l->next->next->next->next->next = new ListNode(6);
    l->next->next->next->next->next->next = new ListNode(7);

    printList(l);

    Solution solu;
    l = solu.reverseKGroup(l, 3);

    printList(l);

    destroyList(l);

    return 0;
}
