// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
// OJ's undirected graph serialization:
// Nodes are labeled uniquely.
// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
// The graph has a total of three nodes, and therefore contains three parts as separated by #.
//    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//    Second node is labeled as 1. Connect node 1 to node 2.
//    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//
// Visually, the graph looks like the following:
//       1
//      / \
//     /   \
//    0 --- 2
//         / \
//         \_/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public:
        // DFS
        UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> &map)
        {
            if (node == NULL)
            {
                return NULL;
            }

            auto it = map.find(node);
            if (it != map.end())
            {
                return it->second;
            }

            UndirectedGraphNode *node2 = new UndirectedGraphNode(node->label);
            map.insert(pair<UndirectedGraphNode*,UndirectedGraphNode*>(node,node2));
            int n = node->neighbors.size();
            for (int i = 0; i < n; i++)
            {
                UndirectedGraphNode *t = clone(node->neighbors[i], map);
                node2->neighbors.push_back(t);
            }
            return node2;
        }

        UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node) {
            unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;
            return clone(node, map);
        }

        // BFS
        UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
            if (node == NULL)
            {
                return NULL;
            }

            queue<UndirectedGraphNode*> Q;
            Q.push(node);
            unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;
            UndirectedGraphNode *node2 = new UndirectedGraphNode(node->label);
            map.insert(pair<UndirectedGraphNode*,UndirectedGraphNode*>(node,node2));
            while (!Q.empty())
            {
                UndirectedGraphNode *t = Q.front();
                Q.pop();
                UndirectedGraphNode *t2 = map.find(t)->second;

                int n = t->neighbors.size();
                for (int i = 0; i < n; i++)
                {
                    auto it = map.find(t->neighbors[i]);
                    if (it != map.end())
                    {
                        t2->neighbors.push_back(it->second);
                    }
                    else
                    {
                        UndirectedGraphNode *neighbor = new UndirectedGraphNode(t->neighbors[i]->label);
                        t2->neighbors.push_back(neighbor);
                        map.insert(pair<UndirectedGraphNode*,UndirectedGraphNode*>(t->neighbors[i], neighbor));
                        Q.push(t->neighbors[i]);
                    }
                }
            }
            return node2;
        }
};

void destroyGraph(UndirectedGraphNode *node, unordered_set<UndirectedGraphNode*> &visited)
{
    if (node != NULL && visited.find(node) == visited.end())
    {
        visited.insert(node);
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++)
        {
            destroyGraph(node->neighbors[i], visited);
        }
        delete node;
    }
}

void printGraph(UndirectedGraphNode *node, unordered_set<UndirectedGraphNode*> &visited)
{
    if (node != NULL && visited.find(node) == visited.end())
    {
        visited.insert(node);
        cout << node->label << "(";
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++)
        {
            cout << node->neighbors[i]->label;
            if (i < n-1)
            {
                cout << " ";
            }
        }
        cout << ") ";
        for (int i = 0; i < n; i++)
        {
            printGraph(node->neighbors[i], visited);
        }
    }
};

int main()
{
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
    UndirectedGraphNode *node3 = new UndirectedGraphNode(3);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node1);
    node3->neighbors.push_back(node1);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node3);

    unordered_set<UndirectedGraphNode*> visited;
    printGraph(node1, visited);
    cout << endl;

    Solution solu;
    UndirectedGraphNode *clone = solu.cloneGraph1(node1);

    visited.clear();
    printGraph(clone, visited);
    cout << endl;

    visited.clear();
    destroyGraph(node1, visited);
    visited.clear();
    destroyGraph(clone, visited);

    return 0;
}
