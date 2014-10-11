// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
        int findMaxDepth(TreeNode *root) {
            if (root == NULL) {
                return 0;
            }
            return max(findMaxDepth(root->left), findMaxDepth(root->right)) + 1;
        }

        // DFS
        int maxDepth1(TreeNode *root) {
            return findMaxDepth(root);
        }

        int maxDepth2(TreeNode *root) {
            if (root == NULL) {
                return 0;
            }

            // BFS, level traversal
            queue<TreeNode*> Q;
            Q.push(root);
            int d = 0;
            int n = 1;
            while (!Q.empty()) {
                d++;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    TreeNode *t = Q.front();
                    Q.pop();

                    if (t->left != NULL) {
                        cnt++;
                        Q.push(t->left);
                    }
                    if (t->right != NULL) {
                        cnt++;
                        Q.push(t->right);
                    }
                }
                n = cnt;
            }
            return d;
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
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    printTree(root);

    Solution solu;
    cout << solu.maxDepth2(root) << endl;

    destroyTree(root);

    return 0;
}
