//Be Blessed with Recursion

#include<iostream>
using namespace std;

void hailStoneSeries(int n){
    cout << n << " ";
    if(n == 1) return;
    else if(n%2 == 0) hailStoneSeries(n/2);
    else hailStoneSeries(3*n+1);
}

int main(){
    int n; cin >> n;
    hailStoneSeries(n);
}

