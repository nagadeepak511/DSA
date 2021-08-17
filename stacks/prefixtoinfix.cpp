#include<iostream>
using namespace std;

class Stack{
public:
    int top=-1, size=100; char elements[100];

    void push(int element){ elements[++top] = element;}
    char pop() { return elements[top--];}
    char peek(){return elements[top];}
};

bool isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

int precedence(char c){
    if(c=='*' || c=='/') return 1;
    else if(c=='+' || c=='-') return 0;
    else return -1;
}

int len(char c[100]){
    int i=0;
    while(c[i] != '\0') i++;
    return i;
}

void display(Stack s){
    while(s.top > -1) cout << s.pop();
}

void pourFromTo(Stack &s1, Stack &s2){
    int balanceCount=0;
    do{
        if(s1.peek() == '(') balanceCount--;
        else if(s1.peek() == ')') balanceCount++;
            s2.push(s1.pop());
        display(s1); cout << endl;
        display(s2); cout << endl << endl;
    }
    while(balanceCount != 0);
}



void convert(char c[100], int i){
    Stack opnds, optrs;
    while(i >= 0){
        if(isOperator(c[i])){
            
                pourFromTo(opnds, optrs);
                pourFromTo(opnds, optrs);
                opnds.push(')');
                pourFromTo(optrs, opnds);
                opnds.push(c[i]);
                pourFromTo(optrs, opnds);
                opnds.push('(');
        }
        else{
            opnds.push(c[i]);
        }
        i--;
    }
    display(opnds);
}

int main(){
    char c[100]; cin.get(c, 100);
    convert(c, len(c)-1);
}