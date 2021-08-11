#include<iostream>
using namespace std;

void digitByDigit(int n){
    if(n==0) return;
    digitByDigit(n/10);
    cout << n%10 << endl;
}

int main(){
    int n; cin >> n;
    digitByDigit(n);
}