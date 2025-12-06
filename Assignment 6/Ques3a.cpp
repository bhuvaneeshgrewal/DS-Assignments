#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertEnd(int x) {
    Node* n = new Node;

    n->data = x;
    n->next = NULL;
    n->prev = tail;
    
    if (!head) 
        head = n;
    else 
        tail->next = n;
    tail = n;
}

int sizeDLL() {
    int c = 0;
    
    Node* temp = head;
    
    while (temp) {
        c++;
        temp = temp->next;
    }
    
    return c;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    
        insertEnd(x);
    }
    
    cout << sizeDLL() << endl;
    
    return 0;
}
