// Given two binary trees, write a function to check if they are equal or not.
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 

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
        bool check(TreeNode *p, TreeNode *q)
        {
            if (p == NULL && q == NULL)
            {
                return true;
            }
            if (p == NULL || q == NULL || p->val != q->val)
            {
                return false;
            }
            return (check(p->left, q->left) && check(p->right, q->right));
        }

        // DFS
        bool isSameTree1(TreeNode *p, TreeNode *q) {
            return check(p, q);
        }

        // BFS
        bool isSameTree2(TreeNode *p, TreeNode *q) {
            if (p == NULL && q == NULL)
            {
                return true;
            }
            if (p == NULL || q == NULL)
            {
                return false;
            }

            // BFS
            queue<TreeNode*> Q1;
            queue<TreeNode*> Q2;
            Q1.push(p);
            Q2.push(q);
            while (!Q1.empty() && !Q2.empty())
            {
                TreeNode *t1 = Q1.front();
                Q1.pop();
                TreeNode *t2 = Q2.front();
                Q2.pop();

                if (t1->val != t2->val)
                {
                    return false;
                }
                if ((t1->left != NULL && t2->left == NULL) || (t1->left == NULL && t2->left != NULL))
                {
                    return false;
                }
                if ((t1->right != NULL && t2->right == NULL) || (t1->right == NULL && t2->right != NULL))
                {
                    return false;
                }
                if (t1->left != NULL && t2->left != NULL)
                {
                    Q1.push(t1->left);
                    Q2.push(t2->left);
                }
                if (t1->right != NULL && t2->right != NULL)
                {
                    Q1.push(t1->right);
                    Q2.push(t2->right);
                }
            }
            return (Q1.empty() && Q2.empty());
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
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->right = new TreeNode(3);
    root1->left->right->left = new TreeNode(4);
    root1->left->right->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->left->right->left = new TreeNode(4);
    root2->left->right->right = new TreeNode(5);

    Solution solu;
    cout << (solu.isSameTree1(root1, root2) ? "true" : "false") << endl;

    destroyTree(root1);
    destroyTree(root2);

    return 0;
}
