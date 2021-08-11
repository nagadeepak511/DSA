#include<iostream>
using namespace std;

int maxDigit(int n){
    if(n<10) return n;
    if(n%10 < maxDigit(n/10)) return maxDigit(n/10);
    return n%10;
}

int main(){
    int n; cin >> n;
    cout << maxDigit(n);
}