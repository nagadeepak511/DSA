#include<iostream>
using namespace std;

void swap(int &a, int &b){
    if(a==b) return;

    a=a+b;
    b=a-b;
    a=a-b;
}

void bubbleSort(int *a, int n, int l=0){
    if(l==n) return;
    
    for(int i=1; i<n; i++){
        if(a[i]<a[i-1]) swap(a[i], a[i-1]);
    }

    bubbleSort(a,n,l+1);
}

int main(){
    int n; cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) cin >> a[i];

    bubbleSort(a,n);

    for(int i=0; i<n; i++) cout << a[i] << " ";
    delete [] a;
}