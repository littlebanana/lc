// Given inorder and postorder traversal of a tree, construct the binary tree.
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
        TreeNode *build(const vector<int> &inorder, int i_l, int i_r, const vector<int> &postorder, int p_l, int p_r)
        {
            if (i_l > i_r)
            {
                return NULL;
            }

            TreeNode *root = new TreeNode(postorder[p_r]);
            int m = i_l;
            for (; m <= i_r && inorder[m] != postorder[p_r]; m++);

            int llen = m - i_l;
            root->left = build(inorder, i_l, i_l+llen-1, postorder, p_l, p_l+llen-1);
            root->right = build(inorder, i_l+llen+1, i_r, postorder, p_l+llen, p_r-1);
            return root;
        }

        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
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

    int post[] = {4, 5, 3, 2, 8, 7, 10, 9, 6, 1};
    vector<int> postorder(post, post+10);

    Solution solu;
    TreeNode *root = solu.buildTree(inorder, postorder);

    printTree(root);

    destroyTree(root);

    return 0;
}
