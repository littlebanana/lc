// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list. 

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    public:
        // DFS approach
        RandomListNode *copy(RandomListNode *head, unordered_map<RandomListNode*,RandomListNode*> &map)
        {
            if (head == NULL)
            {
                return NULL;
            }

            auto it = map.find(head);
            if (it != map.end())
            {
                return it->second;
            }

            RandomListNode *head2 = new RandomListNode(head->label);
            map.insert(pair<RandomListNode*,RandomListNode*>(head,head2));
            head2->next = copy(head->next, map);
            head2->random = copy(head->random, map);
            return head2;
        }

        RandomListNode *copyRandomList1(RandomListNode *head) {
            unordered_map<RandomListNode*,RandomListNode*> map;
            return copy(head, map);
        }

        // BFS approach
        RandomListNode *copyRandomList2(RandomListNode *head) {
            if (head == NULL)
            {
                return NULL;
            }

            queue<RandomListNode*> Q;
            Q.push(head);
            unordered_map<RandomListNode*,RandomListNode*> map;
            RandomListNode *head2 = new RandomListNode(head->label);
            map.insert(pair<RandomListNode*,RandomListNode*>(head,head2));
            while (!Q.empty())
            {
                RandomListNode *t = Q.front();
                Q.pop();
                RandomListNode *t2 = map.find(t)->second;

                if (t->next != NULL)
                {
                    auto it = map.find(t->next);
                    if (it != map.end())
                    {
                        t2->next = it->second;
                    }
                    else
                    {
                        t2->next = new RandomListNode(t->next->label);
                        map.insert(pair<RandomListNode*,RandomListNode*>(t->next,t2->next));
                        Q.push(t->next);
                    }
                }
                if (t->random != NULL)
                {
                    auto it = map.find(t->random);
                    if (it != map.end())
                    {
                        t2->random = it->second;
                    }
                    else
                    {
                        t2->random = new RandomListNode(t->random->label);
                        map.insert(pair<RandomListNode*,RandomListNode*>(t->random,t2->random));
                        Q.push(t->random);
                    }
                }
            }
            return head2;
        }
};

void destroyList(RandomListNode *l)
{
    while (l != NULL)
    {
        RandomListNode *tbd = l;
        l = l->next;
        delete tbd;
    }
}

void printList(RandomListNode *l)
{
    while (l != NULL)
    {
        cout << l->label << "(";
        if (l->random == NULL)
        {
            cout << "#)";
        }
        else
        {
            cout << l->random->label << ")";
        }
        if (l->next != NULL)
        {
            cout << " -> ";
        }
        l = l->next;
    }
    cout << endl;
}

int main()
{
    RandomListNode *head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = new RandomListNode(4);
    head->next->next->next->next = new RandomListNode(5);
    head->next->next->next->next->next = new RandomListNode(6);
    head->random = head;
    head->next->random = head;
    head->next->next->random = head->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next->next->next;

    printList(head);

    Solution solu;
    RandomListNode *head2 = solu.copyRandomList1(head);

    printList(head2);

    destroyList(head);
    destroyList(head2);

    return 0;
}
