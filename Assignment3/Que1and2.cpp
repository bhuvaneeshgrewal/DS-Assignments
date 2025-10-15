#include <iostream>
using namespace std;

class Stack
{
    int a[50];
    int top;
    public:
        Stack() 
        { top = -1; }
        void isEmpty();
        void isFull();

        void display();
        
        void push(int x);
        void pop();       
        
        void peek();
        void reverseString(string a);
};

void Stack::push(int x)
{
    if (top >= 49)
        cout << "Stack Overflow\n";
    else
        a[++top] = x;
}
void Stack::pop()
{
    top < 0 ?   cout << "Stack Underflow\n" : cout << "Popped: " << a[top--] << endl;
}


void Stack::isEmpty()
{
    top < 0 ?   cout << "Stack is empty\n"  : cout << "Stack is not empty\n";
}
void Stack::isFull()
{
    top >= 49 ? cout << "Stack is full\n"   : cout << "Stack is not full\n";
}


void Stack::display()
{
    if (top < 0)
        cout << "Stack is empty\n";
    else
    {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}


void Stack::peek()
{
    top < 0 ?   cout<<"Stack is empty\n"  : cout << "Top element: " << a[top] << endl;
}
void Stack::reverseString(string a)
{
    int len = a.length();
    Stack s;

    for (int i = 0; i < len; i++)
        s.push(a[i]);
    cout<<"Reversed string: ";

    for (int i = 0; i < len; i++)
        cout<<(char)s.a[s.top--];
    cout<<endl;
}


int main()
{
    Stack s;
    string str;
    int choice = 0, value;
    do {
        cout<<endl<<"Menu :"<<endl<<"1. Push"<<endl<< "2. Pop"<<endl<< "3. isEmpty"<<endl<< "4. isFull"<<endl<< "5. Display"<<endl<< "6. Peek"<<endl<< "7. Reverse String"<<endl<< "8. Exit"<<endl<< "Enter your choice: "<<endl;
        cin >> choice;
        switch (choice)
        {
            case 1: cout << "Enter value to push: ";    cin >> value;   s.push(value);   break;
            case 2:     s.pop();        break;
            case 3:     s.isEmpty();    break;
            case 4:     s.isFull();     break;
            case 5:     s.display();    break;
            case 6:     s.peek();       break;
            case 7: cout << "Enter string to reverse: ";    cin >> str; s.reverseString(str);    break;
            case 8:     cout << "Exiting..."<<endl; break;
            default:    cout << "Invalid choice!"<<endl;
        }
    } while (choice != 8);
    return 0;
}