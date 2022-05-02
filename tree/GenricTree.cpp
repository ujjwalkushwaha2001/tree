#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *child;
    Node(int value)
    {
        data = value;
        child = NULL;
    }
};
void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    display(root->child);
}
int main()
{
    struct Node *root = new Node(10);
    root->child = new Node(20);
    root->child = new Node(30);
    root->child = new Node(40);
    display(root);
    return 0;
}