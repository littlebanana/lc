// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its level order traversal as:
// [
//  [3],
//  [9,20],
//  [15,7]
// ]

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<vector<int> > levelOrder1(TreeNode *root) {
            if (root == NULL)
            {
                return vector<vector<int> >();
            }

            // BFS
            vector<vector<int> > levels;
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
            return levels;
        }

        void levelOrder(TreeNode *root, int l, vector<vector<int> > &levels)
        {
            if (root == NULL)
            {
                return;
            }
            if (l > levels.size())      // start a new empty level, will be filled with the context later
            {
                vector<int> empty;
                levels.push_back(empty);
            }
            levels[l-1].push_back(root->val);
            levelOrder(root->left, l+1, levels);
            levelOrder(root->right, l+1, levels);
        }

        // Recursion
        vector<vector<int> > levelOrder2(TreeNode *root) {
            vector<vector<int> > levels;
            levelOrder(root, 1, levels);
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
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printTree(root);

    Solution solu;
    vector<vector<int> > levelorder = solu.levelOrder2(root);

    for (int i = 0; i < levelorder.size(); i++)
    {
        for (int j = 0; j < levelorder[i].size(); j++)
        {
            cout << levelorder[i][j] << " ";
        }
        cout << endl;
    }

    destroyTree(root);

    return 0;
}
