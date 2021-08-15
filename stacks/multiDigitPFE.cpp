#include<iostream>
using namespace std;

class Stack{
public:
    int top=-1, size=100, elements[100];

    void push(int element){ elements[++top] = element;}
    int pop(){ return elements[top--];}
    int peek(){ return elements[top];}
};

int calculate(int opnd1, char optr, int opnd2){
    if(optr == '+') return opnd1+opnd2;
    else if(optr == '-') return opnd1-opnd2;
    else if(optr == '*') return opnd1*opnd2;
    else if(optr == '/') return opnd1/opnd2;
    else return 0;
}

int eval(char c[100]){
    int i=0;
    Stack operands;
    while(c[i] != '\0'){
        if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/'){
            int opnd2 = operands.pop();
            int opnd1 = operands.pop();
            operands.push(calculate(opnd1, c[i], opnd2));
        }
        else{
            int opnd = 0;
            if(c[i] >= '0' && c[i] <= '9'){
                while(c[i] >= '0' && c[i] <= '9'){opnd = opnd*10 + (c[i++]-'0');}
                operands.push(opnd);
            }
        }
        i++;
    }
    return operands.pop();
}

int main(){
    char c[100]; cin.get(c, 100);
    cout << eval(c);
}