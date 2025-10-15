#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the array's length: ";
    cin >> n;
    
    int* x = new int[n];
    
    cout << "Enter the array's elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    
    int c = 0;
    for (int i = 0; i < n; ++i) {
        bool dif = true;
        for (int j = 0; j < i; ++j) {
            if (x[i] == x[j]) {
                dif = false;
                break;
            }
        }
        if (dif)
            ++c;
    }

    cout<<"Total number of unique elements are : " <<c<< endl;
}

int mainreloaded()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10} , n = 10;

    int count = 0;
    for (int i = 0; i <n; i++)
    {
        while (i<n-1 && a[i]==a[i+1])
        {
            i++;
        }
        count++;
    }
    cout<<count;
    return 0;
}