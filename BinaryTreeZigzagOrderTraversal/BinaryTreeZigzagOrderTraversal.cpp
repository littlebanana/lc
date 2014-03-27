// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            vector<vector<int> > zigzag;
            if (root == NULL)
            {
                return zigzag;
            }

            deque<TreeNode*> deQ;
            deQ.push_back(root);
            int n = 1;
            bool popback = false;   // pop from back or front
            while (!deQ.empty())
            {
                int cnt = 0;
                vector<int> level;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *t = (popback ? deQ.back() : deQ.front());
                    (popback ? deQ.pop_back() : deQ.pop_front());
                    level.push_back(t->val);

                    if (popback)
                    {
                        if (t->right != NULL)
                        {
                            cnt++;
                            deQ.push_front(t->right);
                        }
                        if (t->left != NULL)
                        {
                            cnt++;
                            deQ.push_front(t->left);
                        }
                    }
                    else
                    {
                        if (t->left != NULL)
                        {
                            cnt++;
                            deQ.push_back(t->left);
                        }
                        if (t->right != NULL)
                        {
                            cnt++;
                            deQ.push_back(t->right);
                        }
                    }
                }
                zigzag.push_back(level);
                n = cnt;
                popback = !popback;
            }
            return zigzag;
        }
};

void destroyTree(TreeNode *root)
{
    if (root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void printTree(TreeNode *root)
{
    // print in level order
    queue<TreeNode *> Q;
    Q.push(root);
    int n = 1;
    while (!Q.empty())
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *t = Q.front();
            Q.pop();
            if (t == NULL)
            {
                cout << "# ";
            }
            else
            {
                cout << t->val << " ";
                Q.push(t->left);
                Q.push(t->right);
                cnt += 2;
            }
        }
        cout << endl;
        n = cnt;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    printTree(root);

    Solution solu;
    vector<vector<int> > zigzag = solu.zigzagLevelOrder(root);

    for (int i = 0; i < zigzag.size(); i++)
    {
        for (int j = 0; j < zigzag[i].size(); j++)
        {
            cout << zigzag[i][j] << " ";
        }
        cout << endl;
    }

    destroyTree(root);

    return 0;
}
