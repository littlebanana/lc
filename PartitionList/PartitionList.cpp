// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.
// For example,
// Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode *p = NULL;
            ListNode *tp = NULL;
            ListNode *t = head;
            while (t != NULL) {
                if (tp == NULL) {
                    p = (t->val < x ? t : NULL);
                    tp = t;
                    t = t->next;
                } else {
                    if (t->val < x) {
                        if (p == NULL) {
                            // insert in front
                            tp->next = t->next;
                            t->next = head;
                            p = t;
                            head = t;

                            t = tp->next;
                        } else if (p == tp) {
                            // insert in the end
                            p = t;
                            tp = t;
                            t = t->next;
                        } else {
                            // insert in the middle
                            tp->next = t->next;
                            t->next = p->next;
                            p->next = t;
                            p = t;

                            t = tp->next;
                        }
                    } else {
                        tp = t;
                        t = t->next;
                    }
                }
            }
            return head;
        }

        ListNode *partition2(ListNode *head, int x) {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;

            ListNode *p = dummy;
            ListNode *tt = dummy;
            ListNode *t = dummy->next;
            while (t != NULL) {
                if (t->val < x) {
                    if (p != tt) {
                        tt->next = t->next;
                        t->next = p->next;
                        p->next = t;
                        p = p->next;
                        t = tt->next;
                    } else {
                        p = p->next;
                        tt = t;
                        t = t->next;
                    }
                } else {
                    tt = t;
                    t = t->next;
                }
            }
            head = dummy->next;
            delete dummy;
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
    l->next = new ListNode(4);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(2);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next->next = new ListNode(2);
    l->next->next->next->next->next->next = new ListNode(0);
    l->next->next->next->next->next->next->next = new ListNode(7);
    l->next->next->next->next->next->next->next->next = new ListNode(4);
    l->next->next->next->next->next->next->next->next->next = new ListNode(3);
    printList(l);

    Solution solu;
    int x = 3;
    l = solu.partition(l, x);

    printList(l);
    destroyList(l);

    return 0;
}
