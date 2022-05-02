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
// preorder --Root Left Right
void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// Inorder-- left Root Right
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
//postorder---Left Right Root
void postorder(struct Node *root){
    if (root==NULL)
    {
        return;
        
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
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

    //                             10
    //                           /    \
                        //      20    30
    //                         /  \   /  \
                        //   40   50  60  70

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}