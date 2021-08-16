#include<iostream>
using namespace std;

class Stack{
public:
    int top=-1, size=100; char elements[100];

    void push(char element){ elements[++top] = element;}
    char pop(){ return elements[top--];}
    char peek(){return elements[top];}
};

int len(char c[100]){
    int i=0;
    while(c[i]!= '\0') i++;
    return i;
}

void convert(char c[]){
    int i=0;
    Stack operands;
    while(c[i] != '\0'){
        if(c[i]=='+' || c[i]=='-' || c[i]=='*' || c[i]=='/'){
            operands.push(c[i]);
            cout << "(";
        }
        else if(c[i] >= '0' && c[i] <= '9'){
            
        }
        i++;
    }
}

// 
// 
// (1*2)

// *-1/23-/145
// 
// 
// 

int main(){
    char c[100]; cin.get(c, 100);
    convert(c);
}