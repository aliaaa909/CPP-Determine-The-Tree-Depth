#include <iostream>
#include <climits> // untuk INT_MIN dan INT_MAX
using namespace std;

// node
struct Node {
    int label;
    Node *left, *right, *parent;
};

// global pointer variable
Node *root = NULL, *newNode;

void CreateNewTree(int label) {
    if (root != NULL) {
        cout << " = Tree is already created" << endl;
    } else {
        root = new Node;
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << " = " << label << " successfully created as root" << endl;
    }
}

Node *InsertLeft(int label, Node *node) {
    if (root == NULL) {
        cout << " = Tree doesn't exist" << endl;
    } else {
        if (node->left != NULL) {
            cout << " = Left child already exists" << endl;
            return NULL;
        } else {
            newNode = new Node;
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->left = newNode;
            cout << " = " << label << " successfully added to left child of " << newNode->parent->label << endl;
            return newNode;
        }
    }
    return NULL;
}

Node *InsertRight(int label, Node *node) {
    if (root == NULL) {
        cout << " = Tree doesn't exist" << endl;
    } else {
        if (node->right != NULL) {
            cout << " = Right child already exists" << endl;
            return NULL;
        } else {
            newNode = new Node;
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->right = newNode;
            cout << " = " << label << " successfully added to right child of " << newNode->parent->label << endl;
            return newNode;
        }
    }
    return NULL;
}

int sizeTree(Node *node = root) {
    if (!root) {
        cout << "\nTree does not exist." << endl;
        return 0;
    }
    if (!node) return 0;
    return 1 + sizeTree(node->left) + sizeTree(node->right);
}

int TreeHeight(Node *node = root) {
    if (!root) {
        cout << "\nTree does not exist." << endl;
        return 0;
    }
    if (!node) return 0;

    int leftHeight = TreeHeight(node->left);
    int rightHeight = TreeHeight(node->right);

    return max(leftHeight, rightHeight) + 1;
}

void characteristics() {
    cout << " = Size of Tree         : " << sizeTree();
    cout << "\n = Height of Tree       : " << TreeHeight() - 1;
}

// ======== CEK BST ========
bool isBST(Node* node, int minVal, int maxVal) {
    if (node == NULL) return true;

    if (node->label <= minVal || node->label >= maxVal)
        return false;

    return isBST(node->left, minVal, node->label) &&
           isBST(node->right, node->label, maxVal);
}

void checkBST() {
    if (root == NULL) {
        cout << "\n = Tree does not exist." << endl;
    } else {
        if (isBST(root, INT_MIN, INT_MAX)) {
            cout << "\n = Tree is a Binary Search Tree (BST)." << endl;
        } else {
            cout << "\n = Tree is NOT a Binary Search Tree (BST)." << endl;
        }
    }
}

// ========== MAIN ==========
int main() {

    cout << "===============================================" << endl;
    cout << endl;
    cout << " = TREE STRUCTURE :" << endl;
    CreateNewTree(10);

    Node *node5, *node6, *node15;

    node5 = InsertLeft(5, root);
    node15 = InsertRight(15, root);
    node6 = InsertLeft(6, node15);

    cout << "\n=================================================" << endl;
    cout << endl;
    cout << " = TREE CHARACTERISTICS : " << endl;
    characteristics();
    checkBST();
    cout << "\n=================================================" << endl;

    return 0;
}
