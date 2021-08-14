#include<iostream>
using namespace std;

class KStack{
    int k, elements[100];
    int *tops;
    
public:
    KStack(int K){
        k = K;
        tops = new int[k];
        for(int i=0; i<k; i++){
            tops[i] = i*(100/k);
        }
    }

    void push(int element, int i){
        elements[++tops[i]] = element;
    }

    int pop(int i){
        return elements[tops[i]--];
    }

    int peek(int i){
        return elements[tops[i]];
    }

};

int main(){
    KStack s{2};
    s.push(3,0);
    s.push(4,0);
    s.push(5,1);
    s.push(6,1);
    cout << s.pop(0) << " " << s.pop(0) << endl;
    cout << s.pop(1) << " " << s.pop(1) << endl;
}