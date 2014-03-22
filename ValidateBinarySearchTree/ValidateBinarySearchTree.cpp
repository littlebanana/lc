// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
//   1. The left subtree of a node contains only nodes with keys less than the node's key.
//   2. The right subtree of a node contains only nodes with keys greater than the node's key.
//   3. Both the left and right subtrees must also be binary search trees.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void inorder(TreeNode *root, vector<int> &in)
        {
            if (root != NULL)
            {
                inorder(root->left, in);
                in.push_back(root->val);
                inorder(root->right, in);
            }
        }

        // Approach 1: store inorder traversal and check if it is in sorted order
        bool isValidBST1(TreeNode *root) {
            vector<int> in;
            inorder(root, in);
            int n = in.size();
            for (int i = 1; i < n; i++)
            {
                if (in[i] <= in[i-1])
                {
                    return false;
                }
            }
            return true;
        }

        bool inorder2(TreeNode *root, int &prev)
        {
            if (root == NULL)
            {
                return true;
            }

            if (!inorder2(root->left, prev))
            {
                return false;
            }
            if (root->val <= prev)
            {
                return false;
            }
            prev = root->val;
            if (!inorder2(root->right, prev))
            {
                return false;
            }
            return true;
        }

        // shorter version inorder
        bool isValidBST2(TreeNode *root) {
            int prev = INT_MIN;
            return inorder2(root, prev);
        }

        bool check(TreeNode *root, int &min, int &max)
        {
            if (root->left == NULL && root->right == NULL)
            {
                min = root->val;
                max = root->val;
                return true;
            }
            else if (root->left == NULL)
            {
                int rmin = 0;
                int rmax = 0;
                if (!check(root->right, rmin, rmax) || root->val >= rmin)
                {
                    return false;
                }
                min = root->val;
                max = rmax;
                return true;
            }
            else if (root->right == NULL)
            {
                int lmin = 0;
                int lmax = 0;
                if (!check(root->left, lmin, lmax) || root->val <= lmax)
                {
                    return false;
                }
                min = lmin;
                max = root->val;
                return true;
            }
            else
            {
                int lmin = 0;
                int lmax = 0;
                if (!check(root->left, lmin, lmax) || root->val <= lmax)
                {
                    return false;
                }
                int rmin = 0;
                int rmax = 0;
                if (!check(root->right, rmin, rmax) || root->val >= rmin)
                {
                    return false;
                }
                min = lmin;
                max = rmax;
                return true;
            }
        }

        // Approach 2: Recursively check if subtrees are BSTs
        bool isValidBST3(TreeNode *root) {
            if (root == NULL)
            {
                return true;
            }
            int min = 0;
            int max = 0;
            return check(root, min, max);
        }

        bool check2(TreeNode *root, int lbound, int ubound)
        {
            if (root == NULL)
            {
                return true;
            }

            if (root->val <= lbound || root->val >= ubound
                    || !check2(root->left, lbound, root->val) || !check2(root->right, root->val, ubound))
            {
                return false;
            }
            return true;
        }

        // shorter recursive version
        bool isValidBST4(TreeNode *root) {
            check2(root, INT_MIN, INT_MAX);
        }

        // TODO: Morris traversal, why can not pass OJ? runtime error
        bool isValidBST5(TreeNode *root) {
            TreeNode *t = root;
            TreeNode *prev = NULL;
            while (t != NULL)
            {
                if (t->left == NULL)
                {
                    if (prev != NULL && t->val <= prev->val)
                    {
                        return false;
                    }
                    prev = t;
                    t = t->right;
                }
                else
                {
                    TreeNode *p = t->left;
                    for (; p->right != NULL && p->right != t; p = p->right);
                    if (p->right == NULL)
                    {
                        p->right = t;
                        prev = t;
                        t = t->left;
                    }
                    else
                    {
                        p->right = NULL;
                        if (prev != NULL && t->val <= prev->val)
                        {
                            return false;
                        }
                        prev = t;
                        t = t->right;
                    }
                }
            }
            return true;
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
    root->right = new TreeNode(1);

    printTree(root);

    Solution solu;
    cout << (solu.isValidBST2(root) ? "true" : "false") << endl;

    destroyTree(root);

    return 0;
}
