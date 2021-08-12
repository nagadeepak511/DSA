#include<iostream>
using namespace std;

void swap(int &a, int &b){
    if(a==b) return;
    else{
        a=a+b;
        b=a-b;
        a=a-b;
    }
}

void insertion(int *a, int n, int i=1){
    if(i>n) return;
    else{
        int j=i;
        while(a[j] < a[j-1]){
            swap(a[j], a[j-1]);
            j--;
            if(j==0) break;
        }
        insertion(a, n, i+1);
    }
}

int main(){
    int n; cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) cin >> a[i];

    insertion(a, n);

    for(int i=0; i<n; i++) cout << a[i] << " ";
}