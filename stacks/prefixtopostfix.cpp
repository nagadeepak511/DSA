#include<iostream>
using namespace std;

/*
Sample input1:
*+23-45
Sample output1:
23+45-*

Sample input2:
*-A/BC-/AKL
Sample output2:
ABC/-AK/L-*
*/

struct Stack{
    int top=-1, size=100; char elements[100];

    void push(char element){ elements[++top] = element;}
    char pop(){return elements[top--];}
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

void pourFromTo(Stack &s1, Stack &s2){
    int balanceCount=0;
    do{
        if(s1.peek() == '(') balanceCount--;
        else if(s1.peek() == ')') balanceCount++;
            s2.push(s1.pop());
    }
    while(balanceCount != 0);
}

int len(char c[]){
    if(*c == '\0') return 0;

    return 1+len(c+1);
}

void convert(char c[100], int i){
    Stack opnds, optrs;
    while(i>=0){
        if(isOperator(c[i])){
            pourFromTo(opnds, optrs);
            pourFromTo(opnds, optrs);
            opnds.push(')');
            opnds.push(c[i]);
            pourFromTo(optrs, opnds);
            pourFromTo(optrs, opnds);
            opnds.push('(');
        } else opnds.push(c[i]);
        i--;
    }
    while(opnds.top > -1){
        char c=opnds.pop();
        if(c != '(' && c != ')') cout << c;
    }
}

int main(){
    char c[100]; cin >> c;
    convert(c, len(c)-1);
}