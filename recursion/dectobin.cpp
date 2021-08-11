#include<iostream>
using namespace std;

int dectobin(int n){
    if(n==0) return 0;
    else{
        return dectobin(n/2)*10 + n%2;
    }
}

int main(){
    int n; cin >> n;
    cout << dectobin(n);
}