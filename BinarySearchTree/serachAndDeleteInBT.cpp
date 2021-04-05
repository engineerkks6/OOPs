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
Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }

    return searchInBST(root->right, key);
}
Node *inOrderSuccessor(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteInBST(Node *root, int key)
{
    // these two  if is for inequality
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    // For equality
    else
    {
        // Case 1
        if (root->left == NULL)
        {

            Node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 2
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3

        Node *temp = inOrderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (searchInBST(root, 5) == NULL)
    {
        cout << "Key Does Not Exist in BST" << endl;
    }
    else
    {
        cout << "Key Exist in BST" << endl;
    }
    inOrder(root);
    cout << endl;
    root = deleteInBST(root, 5);
    inOrder(root);
    cout << endl;

    return 0;
}