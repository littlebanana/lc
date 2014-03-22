// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
// For example,
//    1
//   / \
//  2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = 12 + 13 = 25. 

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
        void getSum(TreeNode *root, int num, int &sum)
        {
            if (root == NULL)
            {
                return;
            }

            num *= 10;
            num += root->val;
            if (root->left == NULL && root->right == NULL)
            {
                sum += num;
                return;
            }
            else if (root->left == NULL)
            {
                getSum(root->right, num, sum);
            }
            else if (root->right == NULL)
            {
                getSum(root->left, num, sum);
            }
            else
            {
                getSum(root->left, num, sum);
                getSum(root->right, num, sum);
            }
        }

        int sumNumbers(TreeNode *root) {
            int sum = 0;
            getSum(root, 0, sum);
            return sum;
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

    printTree(root);

    Solution solu;
    cout << solu.sumNumbers(root) << endl;

    destroyTree(root);

    return 0;
}
