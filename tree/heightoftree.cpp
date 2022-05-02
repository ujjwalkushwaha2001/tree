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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);
}
bool balance(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int l = height(root->left);
    int r = height(root->right);
    if (abs(l - r) > 1)
    {
        return false;
    }
    bool lh = balance(root->left);
    bool rh = balance(root->right);
    if (lh == false || rh == false)
    {
        return false;
    }
    return true;
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
    cout << height(root) << endl;
    cout << balance(root);
    return 0;
}