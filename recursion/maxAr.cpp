#include<iostream>
using namespace std;

int maxAr(int *a, int n){
    if(n==1) return *a;
    if(*a < maxAr(a+1,n-1)) return maxAr(a+1,n-1);
    return *a;
}

int main(){
    int n; cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) cin >> a[i];

    cout << maxAr(a,n);

    delete [] a;
}