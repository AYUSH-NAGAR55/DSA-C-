// WRITE A C++ PROGRAM TO PERFORM INSERTION, DELETION AND TRAVERSAL OPERATIONS ON A BINARY SEARCH TREE (BST).
/*
This c++ program implements a Binary Search Tree with operations for insertion, deletion and traversal. 
The program provides a menu-driven interface for users to interact with the BST, allowing them to insert nodes,
delete nodes, and perform inorder, preorder and postorder traversals.
*/
#include <iostream>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
    // If the tree is empty, create a root node
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    // Recursively insert the node into the BST
    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal of the BST
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal of the BST
void postorderTraversal(Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, data, inserts = 0;

    while (true) {
        cout << "Binary Search Tree Operations" << endl;
        cout << "1. Insert node" << endl;
        cout << "2. Delete node" << endl;
        cout << "3. Inorder traversal" << endl;
        cout << "4. Preorder traversal" << endl;
        cout << "5. Postorder traversal" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                root = insertNode(root, data);
                inserts++;
                cout << "Node inserted successfully!" << endl;
                cout << "Number of inserts: " << inserts << endl;
                break;
            case 2:
                cout << "Enter data to delete: ";
                cin >> data;
                root = deleteNode(root, data);
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Displaying BST:" << endl;
                cout << "Number of nodes: " << inserts << endl;
                cout << "Root node: ";
                if (root != NULL) {
                    cout << root->data << endl;
                } else {
                    cout << "None" << endl;
                }
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}