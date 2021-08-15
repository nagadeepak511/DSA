#include<iostream>
using namespace std;

class Stack{
public:
    int top=-1, size=100, elements[100];

    void push(int element){ elements[++top] = element;}
    int pop(){return elements[top--];}
    int peek(){return elements[top];}
};

bool isSorted(Stack s){
    if(s.top == 0) return true;
    if(s.pop() > s.peek()) return false;
    return isSorted(s);
} // when poped till there is atleast 1 element -> ascending order

void display(Stack s){
    while(s.top > -1){
        cout << s.pop() << " ";
    }
    cout << endl;
}

void bubbleSort(Stack &s){
    Stack temp;  int pop1, pop2;
    while(!isSorted(s)){
        
        while(s.top > -1){
            if(temp.top == -1) temp.push(s.pop());
            else{
                if(temp.peek() > s.peek()){
                    pop2 = temp.pop();
                    temp.push(s.pop());
                    temp.push(pop2);
                }
                else{
                    temp.push(s.pop());
                }
            }
        }
        while(temp.top > -1) s.push(temp.pop());
    }
}

int main(){
    Stack s;
    for(int i=0; i<10; i++){
        s.push(i);
    }
    bubbleSort(s);
    display(s);
}