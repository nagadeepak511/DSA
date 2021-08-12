#include<iostream>
using namespace std;

void quickSort(int *a, int n){
    
    if(n<=1) return;
    else{
        int lptr=0, rptr=(n-1);

        while(lptr!=rptr){
            while(a[lptr] <= *a && lptr < n-1) lptr++;
            while(a[rptr] >= *a && rptr > 0) rptr--;
            if(lptr > rptr) break;
            int temp = a[lptr];
            a[lptr] = a[rptr];
            a[rptr] = temp;
        }

        int temp = a[rptr];
        a[rptr] = *a;
        *a = temp;

        quickSort(a,rptr);
        if(rptr < n-1)
        quickSort(&a[rptr+1], n-rptr-1);
    }   
}

int main(){
    int n; cin >> n;
    int *a = new int[n];

    for(int i=0; i<n; i++) cin >> a[i];

    quickSort(a, n);

    for(int i=0; i<n; i++) cout << a[i] << " ";
}