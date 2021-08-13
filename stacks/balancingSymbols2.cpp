#include "stacks.cpp"

/*
    { -> -1 && } -> 1
    [ -> -2 && ] -> 2
    ( -> -3 && ) -> 3
*/

bool isBalanced(struct Stack s, int n1=0, int n2=0, int n3=0){
    if(n1 < 0 || n2 < 0 || n3 < 0) return false;
    if(s.top == -1 && n1==0 && n2==0 && n3==0) return true;
    int t=s.pop();
    if(t == 1) n1++;
    else if(t == -1) n1--;
    else if(t == 2) n2++;
    else if(t == -2) n2--;
    else if(t == 3) n3++;
    else if(t == -3) n3--;

    return isBalanced(s, n1, n2, n3);
}

int main(){
    struct Stack s; int n; cin >> n;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        s.push(t);
    }

    cout << isBalanced(s);
}