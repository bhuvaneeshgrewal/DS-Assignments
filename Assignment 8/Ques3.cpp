#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) 
        return new Node(key);
    
    if (key < root->key) 
        root->left = insertNode(root->left, key);
    else if (key > root->key) 
        root->right = insertNode(root->right, key);
    return root;
}

Node* minNode(Node* root) {
    while (root->left) 
        root = root->left;
    
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) 
        return NULL;
    
    if (key < root->key) 
        root->left = deleteNode(root->left, key);
    else if (key > root->key) 
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) 
            return NULL;
        else if (!root->left) 
            return root->right;
        else if (!root->right) 
            return root->left;
        
        Node* t = minNode(root->right);
        
        root->key = t->key;
        root->right = deleteNode(root->right, t->key);
    }

    return root;
}

int maxDepth(Node* root) {
    if (!root) 
        return 0;
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    
    return 1 + (l > r ? l : r);
}

int minDepth(Node* root) {
    if (!root) 
        return 0;
    
    if (!root->left && !root->right) 
        return 1;
    
    if (!root->left) 
        return 1 + minDepth(root->right);
    
    if (!root->right) 
        return 1 + minDepth(root->left);
    
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    
    return 1 + (l < r ? l : r);
}

int main() {
    Node* root = NULL;
    
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    return 0;
}
