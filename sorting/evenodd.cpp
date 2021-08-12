#include<iostream>
using namespace std;

void display(int*a, int n){
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n; cin >> n;
    int *a = new int[n];

    for(int i=0; i<n; i++) cin>> a[i];

    int *lptr=a, *rptr=a+(n-1);

    while(lptr!=rptr){
        while((*lptr) <= *a) lptr++;
        while((*rptr) >= *a) rptr--;
        if(lptr > rptr) break;
        int temp = *lptr;
        *lptr = *rptr;
        *rptr = temp;
    }

    display(a,n);

    delete [] a;
}