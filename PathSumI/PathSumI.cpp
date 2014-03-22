// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
        bool check2(TreeNode *root, int sum)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return (sum == root->val);
            }
            else if (root->left == NULL)
            {
                return check2(root->right, sum-root->val);
            }
            else if (root->right == NULL)
            {
                return check2(root->left, sum-root->val);
            }
            else
            {
                return (check2(root->left, sum-root->val) || check2(root->right, sum-root->val));
            }
        }


        // shorter version
        bool check1(TreeNode *root, int sum)
        {
            if (root == NULL)
            {
                return false;
            }
            if (root->left == NULL && root->right == NULL)
            {
                return (sum == root->val);
            }
            return (check1(root->left, sum-root->val) || check1(root->right, sum-root->val));
        }

        bool hasPathSum(TreeNode *root, int sum) {
            return check1(root, sum);
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
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    printTree(root);

    Solution solu;
    int sum = 22;
    cout << "sum = " << sum << endl;
    cout << (solu.hasPathSum(root, sum) ? "true" : "false") << endl;

    destroyTree(root);

    return 0;
}
