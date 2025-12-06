#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int x) {
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
        head = n;
    }
}

void insertAtEnd(int x) {
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

void insertAfter(int key, int x) {
    if (!head) 
        return;
    
    Node* temp = head;
    
    do {
        if (temp->data == key) {
            Node* n = new Node;
            n->data = x;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void insertBefore(int key, int x) {
    if (!head) 
        return;
    if (head->data == key) {
        insertAtBeginning(x);
        return;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    
    do {
        if (curr->data == key) 
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    
    if (curr->data != key) 
        return;
    
    Node* n = new Node;
    
    n->data = x;
    prev->next = n;
    n->next = curr;
}

void deleteNode(int key) {
    if (!head) 
        return;
    
    Node* curr = head;
    Node* prev = NULL;
    
    do {
        if (curr->data == key) 
            break;
        
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    
    if (curr->data != key) 
        return;
    
    if (curr == head && curr->next == head) {
        delete curr;
        head = NULL;
    } 
    else if (curr == head) {
        Node* last = head;
        
        while (last->next != head) 
            last = last->next;
        head = head->next;
        last->next = head;
        
        delete curr;
    } 
    else {
        prev->next = curr->next;
        delete curr;
    }
}

Node* searchNode(int key) {
    if (!head) 
        return NULL;
    
    Node* temp = head;
    
    do {
        if (temp->data == key) 
            return temp;
        
        temp = temp->next;
    } while (temp != head);
    
    return NULL;
}

void displayCLL() {
    if (!head) {
        cout << endl;
        return;
    }
    
    Node* temp = head;
    
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    cout << head->data << endl;
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
            displayCLL();
        }
    }
    return 0;
}
