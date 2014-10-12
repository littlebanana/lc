// Reverse a linked list from position m to n. Do it in-place and in one-pass.
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
// Note:
// Given m, n satisfy the following condition:
// 1 <= m <= n <= length of list. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if (head == NULL || m == n) {
                return head;
            }

            // now 1 <= m < n <= length

            int cnt = 1;
            ListNode *tail = NULL;
            while (cnt < m) {
                cnt++;
                tail = (tail == NULL ? head : tail->next);
            }

            ListNode *tp = (tail == NULL ? head : tail->next);
            ListNode *t = tp->next;
            while (n > m) {
                ListNode *tn = t->next;
                t->next = tp;
                tp = t;
                t = tn;
                n--;
            }

            // now tp points to the last node to be reversed, t points to the next node
            if (tail == NULL) {
                head->next = t;
                head = tp;
            } else {
                tail->next->next = t;
                tail->next = tp;
            }
            return head;
        }

        ListNode *reverseBetween2(ListNode *head, int m, int n) {
            if (head == NULL || head->next == NULL || m == n) {
                return head;
            }

            ListNode *p = head;
            ListNode *pp = NULL;
            int i = 1;
            for (; i != m; i++) {
                pp = p;
                p = p->next;
            }
            ListNode *t = p->next;
            ListNode *tt = p;
            for (; i != n; i++) {
                ListNode *tn = t->next;
                t->next = tt;
                tt = t;
                t = tn;
            }
            if (pp == NULL) {
                head = tt;
            } else {
                pp->next = tt;
            }
            p->next = t;
            return head;
        }
};

void destroyList(ListNode *l) {
    while (l != NULL) {
        ListNode *tbd = l;
        l = l->next;
        delete tbd;
    }
}

void printList(ListNode *l) {
    while (l != NULL) {
        cout << l->val;
        if (l->next != NULL) {
            cout << "->";
        }
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next->next = new ListNode(6);
    l->next->next->next->next->next->next = new ListNode(7);
    l->next->next->next->next->next->next->next = new ListNode(8);
    l->next->next->next->next->next->next->next->next = new ListNode(9);
    l->next->next->next->next->next->next->next->next->next = new ListNode(10);
    printList(l);

    Solution solu;
    l = solu.reverseBetween(l, 3, 6);

    printList(l);
    destroyList(l);

    return 0;
}
