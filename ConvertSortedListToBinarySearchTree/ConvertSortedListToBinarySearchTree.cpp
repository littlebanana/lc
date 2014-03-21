// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode *convertToBST(ListNode *head, int n)
        {
            if (n == 0)
            {
                return NULL;
            }

            int m = (n+1)/2;
            int cnt = 1;
            ListNode *t = head;
            while (cnt < m)
            {
                cnt++;
                t = t->next;
            }

            TreeNode *root = new TreeNode(t->val);
            root->left = convertToBST(head, m-1);
            root->right = convertToBST(t->next, n-m);
            return root;
        }

        TreeNode *sortedListToBST(ListNode *head) {
            int n = 0;
            ListNode *t = head;
            while (t != NULL)
            {
                n++;
                t = t->next;
            }
            return convertToBST(head, n);
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

void destroyList(ListNode *l)
{
    while (l != NULL)
    {
        ListNode *tbd = l;
        l = l->next;
        delete tbd;
    }
}

void printList(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val;
        if (l->next != NULL)
        {
            cout << "->";
        }
        l = l->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);

    printList(head);

    Solution solu;
    TreeNode *root = solu.sortedListToBST(head);

    printTree(root);

    destroyList(head);
    destroyTree(root);

    return 0;
}
