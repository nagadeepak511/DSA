#include "stacks.cpp"

int main(){
    char s[7];
    cin >> s;
    Stack iStack;
    for(int i=0; i<7; i++){
        if(s[i]>='0' && s[i]<='9') iStack.push(s[i]-'0');
        else{
            int operand2 = iStack.pop();
            int operand1 = iStack.pop();
            if(s[i]=='+') iStack.push(operand1 + operand2);
            else if(s[i]=='-') iStack.push(operand1 - operand2);
            else if(s[i]=='*') iStack.push(operand1 * operand2);
        }
    }
    cout << iStack.peek();
}