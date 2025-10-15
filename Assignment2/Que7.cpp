#include <iostream>
using namespace std;

int invertions(int a[], int n) {
    int count = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i] > a[j])
                ++count;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << "Number of invertions : " << invertions(a, n) << endl;
    return 0;
}