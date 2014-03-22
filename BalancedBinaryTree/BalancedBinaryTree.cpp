// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
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
        bool check(TreeNode *root, int &d)
        {
            if (root == NULL)
            {
                d = 0;
                return true;
            }

            int ld = 0;
            if (!check(root->left, ld))
            {
                return false;
            }
            int rd = 0;
            if (!check(root->right, rd))
            {
                return false;
            }
            if (ld > rd+1 || rd > ld+1)
            {
                return false;
            }
            d = (ld > rd ? ld+1 : rd+1);
            return true;
        }

        bool isBalanced(TreeNode *root) {
            int d = 0;
            return check(root, d);
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
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);

    printTree(root);

    Solution solu;
    cout << (solu.isBalanced(root) ? "true" : "false") << endl;

    destroyTree(root);

    return 0;
}
