#include<iostream>
using namespace std;

void swap(int &a, int &b){
    if(a==b) return;
    a=a+b;
    b=a-b;
    a=a-b;
}

int minIndex(int *a, int n){
    int m=0;
    for(int i=0; i<n; i++){
        if(a[m]>a[i]) m=i;
    }
    return m;
}

void selectionSort(int *a, int n){
    if(n==1) return;

    swap(a[0], a[minIndex(a,n)]);
    selectionSort(a+1, n-1);
}

int main(){
    int n; cin >> n;

    int *a = new int[n];

    for(int i=0; i<n; i++){ cin >> a[i]; }

    selectionSort(a, n);

    for(int i=0; i<n; i++){ cout << a[i] << " ";}
}