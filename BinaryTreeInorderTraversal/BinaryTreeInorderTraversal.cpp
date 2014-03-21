// Given a binary tree, return the inorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [1,3,2].
// Note: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <vector>
#include <stack>
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
        // Approach 1: Morris Traversal, O(1) space, not thread-safe
        vector<int> inorderTraversal1(TreeNode *root) {
            vector<int> inorder;

            // Morris traversal
            TreeNode *t = root;
            while (t != NULL)
            {
                if (t->left == NULL)
                {
                    inorder.push_back(t->val);
                    t = t->right;
                }
                else
                {
                    TreeNode *p = t->left;
                    for (; p->right != NULL && p->right != t; p = p->right);
                    if (p->right == NULL)
                    {
                        p->right = t;
                        t = t->left;
                    }
                    else
                    {
                        inorder.push_back(t->val);
                        p->right = NULL;
                        t = t->right;
                    }
                }
            }
            return inorder;
        }

        // Approach 2: explicit stack, O(h) space
        //             need to keep a variable to tell whether node's left subtree has been explored
        vector<int> inorderTraversal2(TreeNode *root) {
            vector<int> inorder;
            if (root == NULL)
            {
                return inorder;
            }

            // explicit stack
            stack<pair<bool,TreeNode*> > stk;   // <bool,TreeNode*> = visited left child or not + pointer
            stk.push(pair<bool,TreeNode*>(false,root));
            while (!stk.empty())
            {
                TreeNode *t = stk.top().second;
                if (!stk.top().first)
                {
                    stk.top().first = true;
                    if (t->left != NULL)
                    {
                        stk.push(pair<bool,TreeNode*>(false,t->left));
                    }
                }
                else
                {
                    stk.pop();
                    inorder.push_back(t->val);
                    if (t->right != NULL)
                    {
                        stk.push(pair<bool,TreeNode*>(false,t->right));
                    }
                }
            }
            return inorder;
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
    vector<int> inorder = solu.inorderTraversal1(root);

    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;

    destroyTree(root);

    return 0;
}
