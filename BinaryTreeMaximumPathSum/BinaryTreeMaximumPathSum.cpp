// Given a binary tree, find the maximum path sum.
// The path may start and end at any node in the tree.
// For example:
// Given the below binary tree,
//       1
//      / \
//     2   3
// Return 6. 

#include <iostream>
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
        void findPathSum1(TreeNode *root, int &sum, int &max)
        {
            if (root == NULL)
            {
                sum = 0;
                return;
            }

            int lsum = 0;
            findPathSum1(root->left, lsum, max);
            int rsum = 0;
            findPathSum1(root->right, rsum, max);

            max = (max > root->val ? max : root->val);
            max = (max > (root->val+lsum) ? max : (root->val+lsum));
            max = (max > (root->val+rsum) ? max : (root->val+rsum));
            max = (max > (root->val+lsum+rsum) ? max : (root->val+lsum+rsum));

            sum = root->val;
            sum = (sum > (root->val+lsum) ? sum : (root->val+lsum));
            sum = (sum > (root->val+rsum) ? sum : (root->val+rsum));
        }

        void findPathSum2(TreeNode *root, int &sum, int &max)
        {
            if (root == NULL)
            {
                sum = 0;
                return;
            }

            int lsum = 0;
            findPathSum2(root->left, lsum, max);
            int rsum = 0;
            findPathSum2(root->right, rsum, max);

            int thismax = root->val;
            thismax = (lsum > 0 ? thismax+lsum : thismax);
            thismax = (rsum > 0 ? thismax+rsum : thismax);
            max = (max > thismax ? max : thismax);

            int msum = (lsum > rsum ? lsum : rsum);
            sum = (msum > 0 ? root->val+msum : root->val);
        }

        int maxPathSum(TreeNode *root) {
            int sum = 0;
            int max = INT_MIN;          // need this to make it works for negative nodes
            findPathSum2(root, sum, max);
            return max;
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
    cout << solu.maxPathSum(root) << endl;

    destroyTree(root);

    return 0;
}
