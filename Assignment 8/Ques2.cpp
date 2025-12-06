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

Node* searchRec(Node* root, int key) {
    if (!root || root->key == key) 
        return root;
    
    if (key < root->key) 
        return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (key == root->key) 
            return root;
        
        else if (key < root->key) 
            root = root->left;
        else 
            root = root->right;
    }

    return NULL;
}

Node* minNode(Node* root) {
    while (root && root->left) 
        root = root->left;
    
    return root;
}

Node* maxNode(Node* root) {
    while (root && root->right) 
        root = root->right;
    
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchIter(root, key);
    
    if (!curr) 
        return NULL;
    if (curr->right) 
        return minNode(curr->right);
    
    Node* succ = NULL;
    
    while (root) {
        if (key < root->key) { 
            succ = root; root = root->left; 
        }
        else if (key > root->key) 
            root = root->right;
        
        else 
            break;
    }

    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchIter(root, key);
    
    if (!curr) 
        return NULL;
    
    if (curr->left) 
        return maxNode(curr->left);
    
    Node* pred = NULL;
    
    while (root) {
        if (key > root->key) { 
            pred = root; 
            root = root->right; 
        }
        else if (key < root->key) 
            root = root->left;
        
        else 
            break;
    }

    return pred;
}

int main() {
    Node* root = NULL;
    
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 5);
    root = insertNode(root, 15);

    return 0;
}
