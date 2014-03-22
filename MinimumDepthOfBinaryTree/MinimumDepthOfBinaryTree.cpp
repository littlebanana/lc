// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
        // Approach 1: DFS
        int findMinDepth(TreeNode *root)
        {
            if (root == NULL)
            {
                return 0;
            }
            if (root->left == NULL && root->right == NULL)
            {
                return 1;
            }
            else if (root->left == NULL)
            {
                return (1 + findMinDepth(root->right));
            }
            else if (root->right == NULL)
            {
                return (1 + findMinDepth(root->left));
            }
            else
            {
                int l = findMinDepth(root->left);
                int r = findMinDepth(root->right);
                return (l > r ? r+1 : l+1);
            }
        }

        int minDepth1(TreeNode *root) {
            return findMinDepth(root);
        }

        int minDepth2(TreeNode *root) {
            if (root == NULL)
            {
                return 0;
            }

            // BFS, level traversal
            queue<TreeNode*> Q;
            int n = 1;
            int d = 1;
            Q.push(root);
            while (!Q.empty())
            {
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *t = Q.front();
                    Q.pop();

                    if (t->left == NULL && t->right == NULL)
                    {
                        return d;
                    }
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
                d++;
                n = cnt;
            }
            return d;
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
    root->right->left = new TreeNode(4);

    printTree(root);

    Solution solu;
    cout << solu.minDepth2(root) << endl;

    destroyTree(root);

    return 0;
}
