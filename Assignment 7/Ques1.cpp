#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        
        for(int j=i+1;j<n;j++) 
            if(a[j]<a[min]) 
                min=j;
        
        int t=a[i]; 
        a[i]=a[min]; 
        a[min]=t;
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        
        while(j>=0 && a[j]>key){ 
            a[j+1]=a[j]; j--; 
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){ 
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t; 
            }
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    
    for(int i=0;i<n1;i++) 
        L[i]=a[l+i];
    
    for(int i=0;i<n2;i++) 
        R[i]=a[m+1+i];
    
    int i=0,j=0,k=l;
    
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) 
            a[k++]=L[i++];
        else 
            a[k++]=R[j++];
    }
    
    while(i<n1) 
        a[k++]=L[i++];
    while(j<n2) 
        a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(int a[], int low, int high){
    int p=a[high], i=low-1;

    for(int j=low;j<high;j++){
        if(a[j]<p){ 
            i++; 
            int t=a[i]; 
            a[i]=a[j]; 
            a[j]=t; 
        }
    }

    int t=a[i+1]; 
    a[i+1]=a[high]; 
    a[high]=t;
    
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pi=partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++) 
        cin>>a[i];
    
    selectionSort(a,n);
    insertionSort(a,n);
    bubbleSort(a,n);
    mergeSort(a,0,n-1);
    quickSort(a,0,n-1);
    
    for(int i=0;i<n;i++) 
        cout<<a[i]<<" ";

    return 0;
}
