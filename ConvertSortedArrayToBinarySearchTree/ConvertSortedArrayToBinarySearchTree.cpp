// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
        TreeNode *convertToBST(const vector<int> &num, int left, int right)
        {
            if (left > right)
            {
                return NULL;
            }

            int mid = left + (right-left)/2;
            TreeNode *root = new TreeNode(num[mid]);
            root->left = convertToBST(num, left, mid-1);
            root->right = convertToBST(num, mid+1, right);
            return root;
        }

        TreeNode *sortedArrayToBST(vector<int> &num) {
            return convertToBST(num, 0, num.size()-1);
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
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> num(A, A+10);

    Solution solu;
    TreeNode *root = solu.sortedArrayToBST(num);

    printTree(root);
    destroyTree(root);

    return 0;
}
