#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertAtBeginning(int x) {
    Node* n = new Node;

    n->data = x;
    n->prev = NULL;
    n->next = head;
    
    if (head != NULL) 
        head->prev = n;
    else 
        tail = n;
    head = n;
}

void insertAtEnd(int x) {
    Node* n = new Node;
    
    n->data = x;
    n->next = NULL;
    n->prev = tail;
    
    if (tail != NULL) 
        tail->next = n;
    else 
        head = n;
    tail = n;
}

void insertAfter(int key, int x) {
    Node* temp = head;
    
    while (temp && temp->data != key) 
        temp = temp->next;
    
    if (!temp) 
        return;
    
    Node* n = new Node;
    
    n->data = x;
    n->next = temp->next;
    n->prev = temp;
    
    if (temp->next) 
        temp->next->prev = n;
    else 
        tail = n;
    temp->next = n;
}

void insertBefore(int key, int x) {
    if (!head) 
        return;
    
    if (head->data == key) {
        insertAtBeginning(x);
        return;
    }
    
    Node* temp = head->next;
    
    while (temp && temp->data != key) 
        temp = temp->next;
    if (!temp) 
        return;
    
    Node* n = new Node;
    
    n->data = x;
    n->prev = temp->prev;
    n->next = temp;
    
    temp->prev->next = n;
    temp->prev = n;
}

void deleteNode(int key) {
    Node* temp = head;
    
    while (temp && temp->data != key) 
        temp = temp->next;
    if (!temp) 
        return;
    if (temp->prev) 
        temp->prev->next = temp->next;
    else 
        head = temp->next;
    if (temp->next) 
        temp->next->prev = temp->prev;
    else 
        tail = temp->prev;
    delete temp;
}

Node* searchNode(int key) {
    Node* temp = head;
    
    while (temp) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
}

void displayDLL() {
    Node* temp = head;
    
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "1.Insert at beginning \n2.Insert at end \n3.Insert after node \n4.Insert before node \n5.Delete node by value \n6.Search node \n7.Display \n8.Exit" << endl;
        cin >> choice;
        if (choice == 8) 
            break;
        if (choice == 1) {
            int x;
            cin >> x;
            insertAtBeginning(x);
        } 
        else if (choice == 2) {
            int x;
            cin >> x;
            insertAtEnd(x);
        } 
        else if (choice == 3) {
            int key, x;
            cin >> key >> x;
            insertAfter(key, x);
        } 
        else if (choice == 4) {
            int key, x;
            cin >> key >> x;
            insertBefore(key, x);
        } 
        else if (choice == 5) {
            int key;
            cin >> key;
            deleteNode(key);
        } 
        else if (choice == 6) {
            int key;
            cin >> key;
            
            Node* res = searchNode(key);
            
            if (res) 
                cout << "Found\n";
            else 
                cout << "Not Found\n";
        } 
        else if (choice == 7) {
            displayDLL();
        }
    }
    return 0;
}
