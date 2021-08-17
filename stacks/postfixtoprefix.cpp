#include<iostream>
using namespace std;

/*
Input :  Postfix : AB+CD-*
Output : Prefix :  *+AB-CD
Explanation : Postfix to Infix : (A+B) * (C-D)
              Infix to Prefix :  *+AB-CD

Input :  Postfix : ABC/-AK/L-*
Output : Prefix :  *-A/BC-/AKL
Explanation : Postfix to Infix : ((A-(B/C))*((A/K)-L))
              Infix to Prefix :  *-A/BC-/AKL
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

void convert(char c[]){
    int i=0;
    Stack opnds, optrs;
    while(c[i] != '\0'){
        if(isOperator(c[i])){
            pourFromTo(opnds, optrs);
            pourFromTo(opnds, optrs);
            opnds.push(')'); opnds.push(c[i]);
            pourFromTo(optrs, opnds);
            pourFromTo(optrs, opnds);
            opnds.push('(');
        } else opnds.push(c[i]);
        i++;
    }
    while(opnds.top > -1){
        if(opnds.peek() != '(' && opnds.peek() != ')') optrs.push(opnds.pop());
        else opnds.pop();
    }
    while(optrs.top > -1) cout << optrs.pop();
}

int main(){
    char c[100]; cin >> c;
    convert(c);
}