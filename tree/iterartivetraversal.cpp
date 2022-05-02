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
void preorder( struct Node *root)
{
    stack<Node *> s;
    while (!s.empty() || root != NULL)
    {
        if (root != NULL)
        {
            cout << root->data<<" ";
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}
int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    preorder(root);
    return 0;
}