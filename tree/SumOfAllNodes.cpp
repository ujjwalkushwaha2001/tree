#include <iostream>
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
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int sum(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = sum(root->left);
    int r = sum(root->right);
    return root->data + l + r;
}
int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(40);
    root->right->left = new Node(40);
    root->right->right = new Node(40);
    inorder(root);
    cout << endl;
    cout << sum(root) << endl;

    return 0;
}