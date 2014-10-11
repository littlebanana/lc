// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// For example, this binary tree is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//     3    3
// Bonus points if you could solve it both recursively and iteratively. 

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
        bool isMirror(TreeNode *t1, TreeNode *t2) {
            if (t1 == NULL && t2 == NULL) {
                return true;
            }
            if (t1 == NULL || t2 == NULL || t1->val != t2->val) {
                return false;
            }
            return (isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left));
        }

        bool isSymmetric(TreeNode *root) {
            if (root == NULL) {
                return true;
            }
            return isMirror(root->left, root->right);
        }
};

void destroyTree(TreeNode *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void printTree(TreeNode *root) {
    // print in level order
    queue<TreeNode *> Q;
    Q.push(root);
    int n = 1;
    while (!Q.empty()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            TreeNode *t = Q.front();
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    printTree(root);

    Solution solu;
    cout << (solu.isSymmetric(root) ? "true" : "false") << endl;

    destroyTree(root);

    return 0;
}
