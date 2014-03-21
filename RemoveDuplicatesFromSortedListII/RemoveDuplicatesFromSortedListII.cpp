// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3. 

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        // No dummy head
        ListNode *deleteDuplicates1(ListNode *head) {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            bool dup = false;       // indicate whether tp is a duplicate
            ListNode *tpp = NULL;
            ListNode *tp = NULL;
            ListNode *t = head;
            while (t != NULL)
            {
                if (tp != NULL && t->val == tp->val)    // remove the current node
                {
                    dup = true;
                    tp->next = t->next;
                    delete t;
                    t = tp->next;
                }
                else if (tp != NULL && dup == true)     // remove the previous node
                {
                    dup = false;
                    if (tpp == NULL)
                    {
                        head = t;
                        delete tp;
                        tp = t;
                        t = t->next;
                    }
                    else
                    {
                        tpp->next = t;
                        delete tp;
                        tp = t;
                        t = t->next;
                    }
                }
                else
                {
                    dup = false;
                    tpp = tp;
                    tp = t;
                    t = t->next;
                }
            }
            if (dup)        // don't forget to double check after the loop is terminated
            {
                if (tpp == NULL)
                {
                    head = NULL;
                    delete tp;
                }
                else
                {
                    tpp->next = NULL;
                    delete tp;
                }
            }
            return head;
        }

        // Use dummy head
        ListNode *deleteDuplicates2(ListNode *head) {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode *dummy = new ListNode(-1);
            dummy->next = head;

            bool dup = false;
            ListNode *tpp = dummy;
            ListNode *tp = head;
            ListNode *t = head->next;
            while (t != NULL)
            {
                if (t->val == tp->val)     // remove the current node
                {
                    dup = true;
                    tp->next = t->next;
                    delete t;
                    t = tp->next;
                }
                else if (dup == true)       // remove the previous node
                {
                    dup = false;
                    tpp->next = t;
                    delete tp;
                    tp = t;
                    t = tp->next;
                }
                else
                {
                    tpp = tp;
                    tp = t;
                    t = t->next;
                }
            }
            if (dup == true)
            {
                tpp->next = NULL;
                delete tp;
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
    l->next = new ListNode(1);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(3);
    l->next->next->next->next = new ListNode(3);
    printList(l);

    Solution solu;
    l = solu.deleteDuplicates2(l);
    printList(l);

    destroyList(l);

    return 0;
}
