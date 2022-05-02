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
bool rootToNode(Node *root, vector<int> &v, int x)
{
    if (root == NULL)
    {
        return false;
    }
    v.push_back(root->data);
    if (root->data == x)
    {
        return true;
    }
    if (rootToNode(root->left, v, x) || rootToNode(root->right, v, x))
    {
        return true;
    }
    v.pop_back();
    return false;
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
    vector<int> v;
    int x = 70;
    rootToNode(root, v, x);
    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}