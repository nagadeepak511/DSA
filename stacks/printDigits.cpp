#include<iostream>
#include "stacks.cpp"

void printDigits(int n){
    struct Stack s;
    while(n > 9){
        s.push(n%10);
        n/=10;
    }
    s.push(n%10);
    while(s.top >= 0){
        cout << s.pop() << endl;
    }
}

int main(){
    int n; cin >> n;
    printDigits(n);
}