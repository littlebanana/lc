// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7]
//   [9,20],
//   [3],
// ]

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            vector<vector<int> > levels;
            if (root == NULL)
            {
                return levels;
            }

            queue<TreeNode*> Q;
            Q.push(root);
            int n = 1;
            while (!Q.empty())
            {
                int cnt = 0;
                vector<int> level;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *t = Q.front();
                    Q.pop();
                    level.push_back(t->val);

                    if (t->left != NULL)
                    {
                        cnt++;
                        Q.push(t->left);
                    }
                    if (t->right != NULL)
                    {
                        cnt++;
                        Q.push(t->right);
                    }
                }
                levels.push_back(level);
                n = cnt;
            }
            reverse(levels.begin(), levels.end());
            return levels;
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
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    printTree(root);

    Solution solu;
    vector<vector<int> > level = solu.levelOrderBottom(root);

    for (int i = 0; i < level.size(); i++)
    {
        for (int j = 0; j < level[i].size(); j++)
        {
            cout << level[i][j] << " ";
        }
    }
    cout << endl;

    destroyTree(root);

    return 0;
}
