#include<iostream>
using namespace std;

int main()
{
    int a[50] , n;

    cout<<"Enter size of new array : ";
    cin>>n;
    cout<<endl;

    for(int i = 0; i < n ; i++)
    {
        cout<<"Element "<<i+1<<" "<<endl;
        cin>>a[i];
    }

    cout<<"Array created successfully !!"<<endl;

    cout<<"The Sorted Array is : ";
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}    