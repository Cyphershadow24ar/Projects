#include <stdio.h>
#include <stdlib.h>

// Define the color of a node
typedef enum { RED, BLACK } Color;

// Define the structure of a node
typedef struct Node {
    int data;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New node is always RED
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

// Function to fix violations after inserting a node
void fixViolation(Node** root, Node* newNode) {
    Node* parent = NULL;
    Node* grandparent = NULL;
    while ((newNode != *root) && (newNode->color != BLACK) && (newNode->parent->color == RED)) {
        parent = newNode->parent;
        grandparent = newNode->parent->parent;
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
                if (newNode == parent->right) {
                    leftRotate(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rightRotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                newNode = parent;
            }
        } else {
            Node* uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
                if (newNode == parent->left) {
                    rightRotate(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                leftRotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                newNode = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

// Function to insert a node in the Red-Black Tree
void insertNode(Node** root, int data) {
    Node* newNode = createNode(data);
    Node* parent = NULL;
    Node* current = *root;

    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;
    if (parent == NULL)
        *root = newNode;
    else if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    fixViolation(root, newNode);
}

// Function to find the node with minimum value in the tree
Node* minimumNode(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to find a node with a given value
Node* getNode(Node* root, int data) {
    while (root != NULL) {
        if (data == root->data)
            return root;
        else if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Function to delete a node from the Red-Black Tree
void deleteNode(Node** root, Node* node) {
    Node* temp = NULL;
    Node* child = NULL;
    if (node->left == NULL || node->right == NULL)
        temp = node;
    else
        temp = minimumNode(node->right);

    if (temp->left != NULL)
        child = temp->left;
    else
        child = temp->right;

    if (child != NULL)
        child->parent = temp->parent;

    if (temp->parent == NULL)
        *root = child;
    else if (temp == temp->parent->left)
        temp->parent->left = child;
    else
        temp->parent->right = child;

    if (temp != node)
        node->data = temp->data;

    if (temp->color == BLACK)
        fixViolation(root, child);

    free(temp);
}

// Function to perform in-order traversal of the tree
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("(%d,%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
    inOrderTraversal(root->right);
}

// Function to perform pre-order traversal of the tree
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    printf("(%d,%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to perform post-order traversal of the tree
void postOrderTraversal(Node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("(%d,%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
}

// Function to print the Red-Black Tree in a textual pattern
void printTree(Node* root, int space) {
    if (root == NULL) return;

    // Increase distance between levels
    space += 5;

    // Print right child first
    printTree(root->right, space);

    // Print current node
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("(%d,%s)\n", root->data, (root->color == RED) ? "RED" : "BLACK");

    // Print left child
    printTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int choice, data;

    do {
        printf("\nRed-Black Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Traverse in-order\n");
        printf("4. Traverse pre-order\n");
        printf("5. Traverse post-order\n");
        printf("6. Print tree pattern\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertNode(&root, data);
            break;
        case 2:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            deleteNode(&root, getNode(root, data));
            break;
        case 3:
            printf("In-order traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Pre-order traversal: ");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Post-order traversal: ");
            postOrderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Tree Pattern:\n");
            printTree(root, 0);
            break;
        case 7:
            printf("Thank You");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
