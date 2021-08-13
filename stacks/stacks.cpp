#include<iostream>
using namespace std;

struct Stack{
    int size=50, top=-1, elements[50];

    void push(int element){
        if(top == size-1) cout << "Size exceeded\n";
        else{
            elements[top+1] = element;
            top++;
        }
    }

    int pop(){
        if(top < 0){
            cout << "Empty stack\n";
            return 420;
        }
        else{
            top--;
            return elements[top+1];
        }
    }

    int peek(){
        if(top < 0){
            cout << "Empty stack";
            return 420;
        }
        else return elements[top];
    }
};
