#include<iostream>
using namespace std;

struct CharStack{
    int size=50, top=-1; char elements[50];

    void push(char element){
        if(top == size-1) cout << "Size exceeded\n";
        else{
            elements[top+1] = element;
            top++;
        }
    }

    char pop(){
        if(top < 0){
            cout << "Empty stack\n";
            return 420;
        }
        else{
            top--;
            return elements[top+1];
        }
    }

    char peek(){
        if(top < 0){
            cout << "Empty stack";
            return 420;
        }
        else return elements[top];
    }
};