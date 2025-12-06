#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertEnd(char ch) {
    Node* n = new Node;

    n->data = ch;
    n->next = NULL;
    n->prev = tail;
    
    if (!head) 
        head = n;
    else 
        tail->next = n;
    
    tail = n;
}

bool isPalindrome() {
    if (!head) 
        return true;
    
    Node* left = head;
    Node* right = tail;
    
    while (left != right && right->next != left) {
        if (left->data != right->data) 
            return false;
        
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); i++) {
        insertEnd(s[i]);
    }
    
    if (isPalindrome()) 
        cout << "Palindrome\n";
    else 
        cout << "Not Palindrome\n";
    return 0;
}
