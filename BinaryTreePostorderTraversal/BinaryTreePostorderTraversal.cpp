// Given a binary tree, return the postorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [3,2,1].
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
        void reverse(TreeNode *first, TreeNode *last)
        {
            if (first != last)
            {
                TreeNode *tail = last->right;
                TreeNode *tp = first;
                TreeNode *t = first->right;
                while (t != tail)
                {
                    TreeNode *tn = t->right;
                    t->right = tp;
                    tp = t;
                    t = tn;
                }
                first->right = tail;
            }
        }

        void reverseRecord2(vector<int> &postorder, TreeNode* first, TreeNode* last)
        {
            // record in reverse order, i.e. last to first
            // following the right pointer

            reverse(first, last);
            TreeNode *t = last;
            while (t != first->right)
            {
                postorder.push_back(t->val);
                t = t->right;
            }
            reverse(last, first);
        }

        void reverseRecord(vector<int> &postorder, TreeNode *first, TreeNode *last)
        {
            if (first == last)
            {
                postorder.push_back(first->val);
            }
            else
            {
                reverseRecord(postorder, first->right, last);
                postorder.push_back(first->val);
            }
        }

        // Approach 1: Morris traversal
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> postorder;

            // add a dummy root
            TreeNode *dummy = new TreeNode(-1);
            dummy->left = root;

            TreeNode *t = dummy;
            while (t != NULL)
            {
                if (t->left == NULL)
                {
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
                        reverseRecord2(postorder, t->left, p);
                        p->right = NULL;
                        t = t->right;
                    }
                }
            }
            root = dummy->left;
            delete dummy;

            return postorder;
        }


        // Approach 2: explicit stack, O(h) space
        //             need to keep a variable to tell whether node's left subtree has been explored
        vector<int> postorderTraversal2(TreeNode *root) {
            vector<int> postorder;
            if (root == NULL)
            {
                return postorder;
            }

            stack<pair<bool,TreeNode*> > stk;   // whether both children are explored
            stk.push(pair<bool,TreeNode*>(false,root));
            while (!stk.empty())
            {
                TreeNode *t = stk.top().second;
                if (!stk.top().first)
                {
                    stk.top().first = true;
                    if (t->right != NULL)
                    {
                        stk.push(pair<bool,TreeNode*>(false,t->right));
                    }
                    if (t->left != NULL)
                    {
                        stk.push(pair<bool,TreeNode*>(false,t->left));
                    }
                }
                else
                {
                    stk.pop();
                    postorder.push_back(t->val);
                }
            }
            return postorder;
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
    vector<int> postorder = solu.postorderTraversal2(root);

    for (int i = 0; i < postorder.size(); i++)
    {
        cout << postorder[i] << " ";
    }
    cout << endl;

    destroyTree(root);

    return 0;
}
