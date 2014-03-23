// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.
// Note:
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution? 

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void inorder1(TreeNode *root, vector<TreeNode *> &ptrs)
        {
            if (root->left == NULL && root->right == NULL)
            {
                ptrs.push_back(root);
            }
            else if (root->left == NULL)
            {
                ptrs.push_back(root);
                inorder1(root->right, ptrs);
            }
            else if (root->right == NULL)
            {
                inorder1(root->left, ptrs);
                ptrs.push_back(root);
            }
            else
            {
                inorder1(root->left, ptrs);
                ptrs.push_back(root);
                inorder1(root->right, ptrs);
            }
        }

        // O(n) space, inorder traverse
        void recoverTree1(TreeNode *root)
        {
            if (root != NULL)
            {
                vector<TreeNode *> ptrs;
                inorder1(root, ptrs);

                int L = ptrs.size();
                if (L < 2)
                {
                    return;
                }

                cout << "L = " << L << endl;

                int p = 0;
                int i = 0;
                while (i < L)
                {
                    cout << i <<endl;
                    if (i == 0 && ptrs[i]->val > ptrs[i+1]->val)
                    {
                        p = i;
                        break;
                    }
                    if (i > 0 && i < L && (ptrs[i]->val > ptrs[i+1]->val || ptrs[i]->val < ptrs[i-1]->val))
                    {
                        p = i;
                        break;
                    }
                    i++;
                }
                cout << "p = " << p << endl;
                i++;
                int q = i;
                while (i < L)
                {
                    cout << i <<endl;
                    if (i == L-1 && ptrs[i]->val < ptrs[i-1]->val)
                    {
                        q = i;
                        break;
                    }
                    if (i >= 0 && i < L-1 && (ptrs[i]->val > ptrs[i+1]->val || ptrs[i]->val < ptrs[i-1]->val))
                    {
                        q = i;
                        break;
                    }
                    i++;
                }

                int tmp = ptrs[p]->val;
                ptrs[p]->val = ptrs[q]->val;
                ptrs[q]->val = tmp;
            }
        }

        void inorder2(TreeNode *root, vector<TreeNode*> &ptrs)
        {
            if (root != NULL)
            {
                inorder2(root->left, ptrs);
                ptrs.push_back(root);
                inorder2(root->right, ptrs);
            }
        }

        void recoverTree2(TreeNode *root) {
            vector<TreeNode*> ptrs;
            inorder2(root, ptrs);
            TreeNode *p = NULL;
            TreeNode *q = NULL;
            int n = ptrs.size();
            for (int i = 1; i < n; i++)
            {
                if (ptrs[i-1]->val > ptrs[i]->val)
                {
                    q = ptrs[i];
                    if (p == NULL)
                    {
                        p = ptrs[i-1];
                    }
                }
            }
            swap(p->val, q->val);
        }

        void inorder3(TreeNode *root, TreeNode * &prev, TreeNode * &p, TreeNode * &q)
        {
            if (root != NULL)
            {
                inorder3(root->left, prev, p, q);
                if (prev != NULL && root->val < prev->val)
                {
                    q = root;
                    if (p == NULL)
                    {
                        p = prev;
                    }
                }
                prev = root;
                inorder3(root->right, prev, p, q);
            }
        }

        void recoverTree3(TreeNode *root) {
            TreeNode *p = NULL;
            TreeNode *q = NULL;
            TreeNode *prev = NULL;
            inorder3(root, prev, p, q);
            if (p != NULL && q != NULL)
            {
                swap(p->val, q->val);
            }
        }

        void recoverTree4(TreeNode *root) {
            TreeNode *p = NULL;
            TreeNode *q = NULL;
            TreeNode *prev = NULL;
            // Morris traversal
            TreeNode *t = root;
            while (t != NULL)
            {
                if (t->left == NULL)
                {
                    if (prev != NULL && t->val < prev->val)
                    {
                        q = t;
                        if (p == NULL)
                        {
                            p = prev;
                        }
                    }
                    prev = t;
                    t = t->right;
                }
                else
                {
                    TreeNode *tp = t->left;
                    for (; tp->right != NULL && tp->right != t; tp = tp->right);
                    if (tp->right == NULL)
                    {
                        tp->right = t;
                        t = t->left;
                    }
                    else
                    {
                        tp->right = NULL;
                        if (prev != NULL && t->val < prev->val)
                        {
                            q = t;
                            if (p == NULL)
                            {
                                p = prev;
                            }
                        }
                        prev = t;
                        t = t->right;
                    }
                }
            }
            if (p != NULL && q != NULL)
            {
                swap(p->val, q->val);
            }
        }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solu;
    solu.recoverTree1(root);

    return 0;
}
