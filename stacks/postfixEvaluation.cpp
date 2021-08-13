#include "stacks.cpp"

int main(){
    char s[50];
    cin >> s;
    Stack iStack;
    int i=0;
    while(s[i] != '\0'){
        if(s[i]>='0' && s[i]<='9') iStack.push(s[i]-'0');
        else{
            int operand2 = iStack.pop();
            int operand1 = iStack.pop();
            if(s[i]=='+') iStack.push(operand1 + operand2);
            else if(s[i]=='-') iStack.push(operand1 - operand2);
            else if(s[i]=='*') iStack.push(operand1 * operand2);
        }
        i++;
    }
    cout << iStack.peek();
}