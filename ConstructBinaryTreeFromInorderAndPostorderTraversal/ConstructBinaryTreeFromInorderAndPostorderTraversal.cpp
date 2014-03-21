// Given preorder and inorder traversal of a tree, construct the binary tree.
// Note:
// You may assume that duplicates do not exist in the tree. 

#include <iostream>
#include <vector>
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
        TreeNode *build(const vector<int> &preorder, int p_l, int p_r, const vector<int> &inorder, int i_l, int i_r)
        {
            if (p_l > p_r)
            {
                return NULL;
            }

            TreeNode *root = new TreeNode(preorder[p_l]);
            int m = i_l;
            for (; m <= i_r && inorder[m] != preorder[p_l]; m++);

            int llen = m - i_l;
            root->left = build(preorder, p_l+1, p_l+llen, inorder, i_l, m-1);
            root->right = build(preorder, p_l+llen+1, p_r, inorder, m+1, i_r);
            return root;
        }

        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
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
    int in[] = {2, 4, 3, 5, 1, 7, 8, 6, 9, 10};
    vector<int> inorder(in, in+10);

    int pre[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> preorder(pre, pre+10);

    Solution solu;
    TreeNode *root = solu.buildTree(preorder, inorder);

    printTree(root);

    destroyTree(root);

    return 0;
}
