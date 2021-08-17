#include<iostream>
using namespace std;

int fall(int *a, int n, int *max, int &sum, double &avg){
    if(*max < *a) *max = *a;
    sum += *a;

    if(n==1){
        return *max;
    }

    int nxtMin = fall(a+1, n-1, max, sum, avg);
    if(nxtMin > *a) return *a;
    avg = sum*1.0/n;
    return nxtMin;
}

int main(){
    int n; cin >> n;
    int a[50]; for(int i=0; i<n; i++) cin >> a[i];
    int *max = new int(a[0]), sum=0; double avg=0;
    cout << fall(a,n,max,sum, avg) << " " << *max << " " << sum << " " << avg << endl;

    delete max;
}