// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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
        vector<TreeNode *> generate(int left, int right)
        {
            if (left > right)
            {
                TreeNode *NIL = NULL;
                vector<TreeNode *> tmp;
                tmp.push_back(NIL);
                return tmp;
            }

            vector<TreeNode *> trees;
            for (int i = left; i <= right; i++)
            {
                vector<TreeNode *> ltrees = generate(left, i-1);
                vector<TreeNode *> rtrees = generate(i+1, right);
                int L = ltrees.size();
                int R = rtrees.size();
                for (int l = 0; l < L; l++)
                {
                    for (int r = 0; r < R; r++)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = ltrees[l];
                        root->right = rtrees[r];
                        trees.push_back(root);
                    }
                }
            }
            return trees;
        }

        vector<TreeNode *> generateTrees(int n) {
            return generate(1, n);
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
    Solution solu;
    vector<TreeNode *> trees = solu.generateTrees(3);

    for (int i = 0; i < trees.size(); i++)
    {
        printTree(trees[i]);
    }
    for (int i = 0; i < trees.size(); i++)
    {
        destroyTree(trees[i]);
    }

    return 0;
}
