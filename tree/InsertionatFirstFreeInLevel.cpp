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
void traverse(struct Node *root)
{
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node *a = q.front();
        if (a->left != NULL)
        {
            q.push(a->left);
        }
        if (a->right != NULL)
        {
            q.push(a->right);
        }
        q.pop();
        cout << a->data << " ";
    }
}
void insertAtFirstLevel(struct Node **root, int key)
{
    if (*root == NULL)
    {
        *root = new Node(key);
        return;
    }
    else
    {
        queue<struct Node *> q1;
        q1.push(*root);
        while (!q1.empty())
        {
            struct Node *a1 = q1.front();
            if (a1->left == NULL)
            {
                a1->left = new Node(key);
                return;
            }
            if (a1->right == NULL)
            {
                a1->right = new Node(key);
                return;
            }
            if (a1->left != NULL)
            {
                q1.push(a1->left);
            }
            if (a1->right != NULL)
            {
                q1.push(a1->right);
            }
            q1.pop();
        }
    }
}
void display(struct Node *root)
{
    traverse(root);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = NULL;
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    insertAtFirstLevel(&root, 4);
    display(root);
    return 0;
}