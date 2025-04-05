/*
Programmer: Ricardo Ramirez
Program Name: Tree Functio removing a value
Date : 04/09/24
Version 1.9
Program that will remove a value from the binary search tree.*/

#include <iostream>
using namespace std;

struct Node {       // defining a structure named Node
    int data;       // data stored in the node 
    Node* left;     // pointer to left child
    Node* right;       // pointer to right child 
};

Node* GetNewNode(int data) {        // creates a new node with teh data given
    Node* newNode = new Node();     // dynamically allocates memory 
    newNode->data = data;           // passes data to new Node
    newNode->left = newNode->right = NULL;      //set left and right child pointer to NULL
    return newNode;
}

Node* Insert(Node* root, int data) {        // insert the data into the BST
    if (root == NULL) {     // if tree uis empty then we reachhed end of leaf
        root = GetNewNode(data);    //creates new Node 
    }
    else if (data <= root->data) { //if less than or equal to root data
        root->left = Insert(root->left, data);      // we insert on left
    }
    else {          // if data greater than the root 
        root->right = Insert(root->right, data);        // insert on the right of subtree
    }
    return root;
}

Node* FindMin(Node* node) { // function to find the minimun 
    if (node == NULL) return NULL;      // if tree is empty return NULL
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* Delete(Node* root, int data) { // function to delete a Node with the info given
    if (root == NULL) return root;      // if the root is empty we retunr NULL
    else if (data < root->data) root->left = Delete(root->left, data);  // else if the data less that the data we ldelete what is on the left
    else if (data > root->data) root->right = Delete(root->right, data); // same for the right 

    else //if found we will delete 
    {
        //case 1: No child or one child
        if (root->left == NULL) { // if the left node is empty 
            Node* temp = root->right;   // store thr right child 
            delete root;    // delete Node
            return temp;
        }
        else if (root->right == NULL) {         // if the right node is empty
            Node* temp = root->left;        // we store the left 
            delete root; // deletes
            return temp;
        }
        //case 2: Two children
        else {
            Node* temp = FindMin(root->right); // Find the minimum value in the right subtree
            root->data = temp->data; // Copy the inorder successor's content to this node
            root->right = Delete(root->right, temp->data); // Delete the inorder successor
        }
    }
    return root;
}

void Inorder(Node* root) { // Function to perform inorder traversal of the BST
    if (root == NULL) return; // If the tree is empty, return
    Inorder(root->left); // Recursively traverse the left subtree
    cout << root->data << " "; // Print the data of the current node
    Inorder(root->right); // Recursively traverse the right subtree
}

int main() {
    Node* root = NULL; // Creating an empty tree
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);

    cout << "Inorder traversal of the BST before deletion (middle number is the root): ";
    Inorder(root);
    cout << endl;

    int valueToDelete = 10;
    root = Delete(root, valueToDelete);
    cout << "Inorder traversal of the BST after deletion of " << valueToDelete << ": ";
    Inorder(root);
    cout << endl;

    return 0;
}