#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
void rightview(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *p = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << p->data << " ";
            }
            if (p->left != NULL)
            {
                q.push(p->left);
            }

            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
    }
}
main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    rightview(root);
    return 0;
}