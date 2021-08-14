#include "charstack.cpp"

int precedence(char c){
    if(c=='*' || c=='/') return 1;
    else if(c=='+' || c=='-') return 0;
    else return -1;
}

void convert(char infixExp[]){
    CharStack optrStack;
    int i=0;
    while(infixExp[i] !='\0'){
        if(infixExp[i] >= '0' && infixExp[i] <= '9'){cout << infixExp[i];}
        else if(infixExp[i] == '('){optrStack.push(infixExp[i]);}
        else if(infixExp[i] == ')'){
            while(optrStack.peek() != '(') cout << optrStack.pop();
            optrStack.pop();
        }
        else{
            while(optrStack.top > -1 && precedence(optrStack.peek()) >= precedence(infixExp[i])){
                cout << optrStack.pop();
            }
            optrStack.push(infixExp[i]);
        }
        i++;
    }
    while(optrStack.top > -1) cout << optrStack.pop();
}

int main(){
    char expression[50];
    cin >> expression;

    convert(expression);
}