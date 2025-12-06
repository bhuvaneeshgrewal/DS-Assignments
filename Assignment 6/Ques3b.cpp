#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    
    if (!head) {
        head = n;
        head->next = head;
    } 
    else {
        Node* temp = head;
        
        while (temp->next != head) 
            temp = temp->next;
        
        temp->next = n;
        n->next = head;
    }
}

int sizeCLL() {
    if (!head) 
        return 0;
    
    int c = 0;
    Node* temp = head;
    
    do {
        c++;
        temp = temp->next;
    } while (temp != head);
    
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
    
    cout << sizeCLL() << endl;
    
    return 0;
}
