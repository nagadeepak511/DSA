#include<iostream>
using namespace std;

void swap1(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

void swap2(int *a, int *b){
    *a = *a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

void swap3(int *a, int &b){
    *a = *a+b;
    b=*a-b;
    *a=*a-b;
}

int main(){
    int a1=2,*a2,*a3,b1=3,*b2,b3=3;
    int p2=2, p3=2, q2=3;
    a2=&p2;
    a3=&p3;
    b2=&q2;
    swap1(a1,b1);
    swap2(a2,b2);
    swap3(a3,b3);
    cout << a1 << " " << b1 << endl;
    cout << *a2 << " " << *b2 << endl;
    cout << *a3 << " " << b3 << endl;
}