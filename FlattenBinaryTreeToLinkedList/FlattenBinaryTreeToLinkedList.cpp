// Given a binary tree, flatten it to a linked list in-place.
// For example,
// Given
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
// The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
        // Morris traversal
        void flatten1(TreeNode *root) {
            TreeNode *t = root;
            while (t != NULL)
            {
                if (t->left == NULL)
                {
                    t = t->right;
                }
                else
                {
                    TreeNode *p = t->left;
                    for (; p->right != NULL; p = p->right);

                    p->right = t->right;
                    t->right = t->left;
                    t->left = NULL;

                    t = t->right;
                }
            }
        }

        TreeNode* getFlattenedTail(TreeNode *root)
        {
            if (root == NULL)
            {
                return NULL;
            }

            TreeNode *l = getFlattenedTail(root->left);
            TreeNode *r = getFlattenedTail(root->right);
            if (l == NULL && r == NULL)
            {
                return root;
            }
            else if (l == NULL)
            {
                return r;
            }
            else if (r == NULL)
            {
                root->right = root->left;
                root->left = NULL;
                return l;
            }
            else
            {
                l->right = root->right;
                root->right = root->left;
                root->left = NULL;
                return r;
            }
        }

        void flatten2(TreeNode *root) {
            getFlattenedTail(root);
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
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(6);

    printTree(root);

    Solution solu;
    solu.flatten1(root);

    printTree(root);

    destroyTree(root);

    return 0;
}
