// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
        void generate(TreeNode *root, int sum, vector<int> trace, vector<vector<int> > &paths)
        {
            if (root == NULL)
            {
                return;
            }
            if (root->left == NULL && root->right == NULL)  // leaf
            {
                if (root->val == sum)
                {
                    trace.push_back(root->val);
                    paths.push_back(trace);
                }
            }
            else
            {
                trace.push_back(root->val);
                generate(root->left, sum-root->val, trace, paths);
                generate(root->right, sum-root->val, trace, paths);
            }
        }

        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<vector<int> > paths;
            vector<int> trace;
            generate(root, sum, trace, paths);
            return paths;
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    printTree(root);

    Solution solu;
    int sum = 22;
    cout << "sum = " << sum << endl;
    vector<vector<int> > paths = solu.pathSum(root, sum);

    for (int i = 0; i < paths.size(); i++)
    {
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }

    destroyTree(root);

    return 0;
}
