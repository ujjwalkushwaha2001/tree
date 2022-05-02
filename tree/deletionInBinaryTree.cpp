#include <iostream>
#include <queue>
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
void traversal(struct Node *root)
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

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    traversal(root);
    return 0;
}