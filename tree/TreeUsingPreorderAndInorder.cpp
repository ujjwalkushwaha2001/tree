#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
Node *BuildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = BuildTree(preorder, inorder, start, pos - 1);
    node->right = BuildTree(preorder, inorder, pos + 1, end);
    return node;
}
void inorderprint(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}
int main()
{
    int preorder[] = {100, 20, 40, 50, 30, 60, 70};
    int inorder[] = {40, 20, 50, 100, 60, 30, 70};
    struct Node *root = BuildTree(preorder, inorder, 0, 6);
    inorderprint(root);
    return 0;
}