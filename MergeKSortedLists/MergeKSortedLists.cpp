// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity. 

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *mergeLists(ListNode *l1, ListNode *l2)
        {
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

        ListNode *merge(const vector<ListNode *> &lists, int left, int right)
        {
            if (left > right)
            {
                return NULL;
            }
            if (left == right)
            {
                return lists[left];
            }
            if (left + 1 == right)
            {
                return mergeLists(lists[left], lists[right]);
            }
            int mid = left + (right-left)/2;
            ListNode *l1 = merge(lists, left, mid);
            ListNode *l2 = merge(lists, mid+1, right);
            return mergeLists(l1, l2);
        }

        // Complexity: T(sum_{i=0}^{K} n_{i}) = T(sum_{i=0}^{K/2} n_{i}) + T(sum_{i=K/2+1}^{K} n_{i}) + O(N)
        //                                    = ... = NlogK
        ListNode *mergeKLists1(vector<ListNode *> &lists) {
            return merge(lists, 0, lists.size()-1);
        }

        ListNode *mergeKLists2(vector<ListNode *> &lists) {
            if (lists.empty())
            {
                return NULL;
            }

            int n = lists.size();
            for (int l = 1; l < n; l *= 2)
            {
                for (int i = 0; i < n; i += 2*l)
                {
                    int j = i + l;
                    if (j < n)
                    {
                        lists[i] = mergeLists(lists[i], lists[j]);
                    }
                }
            }
            return lists[0];
        }

        // Complexity: O(KN)
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            if (lists.empty())
            {
                return NULL;
            }

            int n = lists.size();
            for (int i = 1; i < n; i++)
            {
                lists[0] = mergeLists(lists[0], lists[i]);
            }
            return lists[0];
        }
};

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
    ListNode *l1 = new ListNode(0);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);
    ListNode *l2 = new ListNode(-1);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(19);

    vector<ListNode *> lists;
    lists.push_back(l1);
    lists.push_back(l2);

    Solution solu;
    ListNode *merged = solu.mergeKLists(lists);

    printList(merged);

    destroyList(merged);

    return 0;
}
