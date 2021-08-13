#include "stacks.cpp"

// {{{}{}}} == 0 0 0 1 0 1 1 1

bool isBalanced(struct Stack s, int n1=0, int n2=0){
    if(s.top == -1){
        if(n1==n2) return true;
        else return false;
    }
    else if(n1 > n2) return false;
    int t=s.pop();
    if(t == 0) n1++;
    else if(t == 1) n2++;
    return isBalanced(s, n1, n2);
}

int main(){
    struct Stack s; int n; cin >> n;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        s.push(t);
    }

    cout << isBalanced(s);
}