// Given a binary tree
//    struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//    }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
// Note:
//    You may only use constant extra space.
//    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// For example,
// Given the following perfect binary tree,
//         1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
// After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL

#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode *t = root;
            while (t != NULL) {
                // populate one level lower
                TreeLinkNode *next = NULL;      // parent level start point for next level iteration
                TreeLinkNode *prev = NULL;
                for (; t != NULL; t = t->next) {
                    if (t->left != NULL) {
                        if (prev == NULL) {
                            prev = t->left;
                            next = t->left;
                        } else {
                            prev->next = t->left;
                            prev = t->left;
                        }
                    }
                    if (t->right != NULL) {
                        if (prev == NULL)
                        {
                            prev = t->right;
                            next = t->right;
                        } else {
                            prev->next = t->right;
                            prev = t->right;
                        }
                    }
                }
                t = next;
            }
        }
};

void destroyTree(TreeLinkNode *root)
{
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void printTree(TreeLinkNode *root)
{
    // print in level order
    queue<TreeLinkNode *> Q;
    Q.push(root);
    int n = 1;
    while (!Q.empty()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            TreeLinkNode *t = Q.front();
            Q.pop();
            if (t == NULL) {
                cout << "# ";
            } else {
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

int main() {
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    printTree(root);

    Solution solu;
    solu.connect(root);

    TreeLinkNode *t = root;
    while (t != NULL) {
        TreeLinkNode *p = t;
        t = NULL;
        while (p != NULL) {
            if (p->left != NULL && t == NULL) {
                t = p->left;
            }
            if (p->right != NULL && t == NULL) {
                t = p->right;
            }
            cout << p->val << "->";
            if (p->next == NULL) {
                cout << "NIL" << endl;
            }
            p = p->next;
        }
    }

    destroyTree(root);

    return 0;
}
