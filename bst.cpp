#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <assert.h>

using namespace std;

// Initialize the binary search tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

};

//Allocate a node
Node *new_node(int data_value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node -> data = data_value;
    node -> left = node -> right = NULL;
    return node;
}

// Insert a node into the BST
Node *insertion_node (Node *root, int node_value)
{
    
    //root is null
    if (!root)
    {   
        Node *cur_node = new_node(node_value);
        return cur_node;
    }
    
    else
    {
        if (node_value < root -> data)
        {
            root -> left = insertion_node (root -> left, node_value);
        }
        else
        {
            root -> right = insertion_node (root -> right, node_value);
        }
    }

    return root;
    
}

void inorder_traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder_traversal(root -> left );
    cout << root->data << "; ";
    inorder_traversal(root -> right);
    
}

void preorder_traversal(Node *root)
{
    if (!root)
    {
        return;
    }

    cout << root->data << "; ";
    preorder_traversal (root -> left);
    preorder_traversal (root -> right);

}

void postorder_traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    postorder_traversal(root-> left);
    postorder_traversal(root-> right);
    cout << root->data << "; ";
}


int main()
{
    Node *Root = NULL;
    Root = insertion_node(Root,7);
    insertion_node(Root,1);
    insertion_node(Root,5);
    insertion_node(Root,9);
    insertion_node(Root,2);
    insertion_node(Root,13);
    insertion_node(Root,17);
    insertion_node(Root,11);
    insertion_node(Root,0);

    cout << "Insertion finish.\n\n";

    cout << "Inorder Traversal\n";
    inorder_traversal(Root);
    cout << "\n\n\n";

    cout << "Preorder Traversal\n";
    preorder_traversal(Root);
    cout << "\n\n\n";

    cout << "Postorder Traversal\n";
    postorder_traversal(Root);
    cout << "\n\n\n";


    return 0;
}