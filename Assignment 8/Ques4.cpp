#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

bool check(Node* root, long long low, long long high) {
    if (!root) 
        return true;
    
    if (root->data <= low || root->data >= high) 
        return false;
    
    return check(root->left, low, root->data) &&
           check(root->right, root->data, high);
}

bool isBST(Node* root) {
    return check(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(10);
    
    root->left = new Node(5);
    root->right = new Node(20);

    return 0;
}
