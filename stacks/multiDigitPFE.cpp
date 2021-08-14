#include<iostream>
using namespace std;

class CharStack{
public:
    int top=-1, size=100; char elements[100];

    void push(char c){ elements[++top] = c; }
    char pop(){ return elements[top--];}
    char peek(){ return elements[top];}
};

int main(){
    
}