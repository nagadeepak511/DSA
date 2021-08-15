#include<iostream>
using namespace std;

class Node {
public:
    int integer=0; char character; bool boolean; double dFloat; bool isCharacter;
};

class GenericStack{
public:
    int top=-1, size=100; Node elements[100];

    void push(Node &element){elements[++top] = element;}
    Node pop(){return elements[top--];}
    Node peek(){return elements[top];}
};

// int main(){
//     GenericStack s;
//     Node n1; n1.integer = 10; s.push(n1);
//     Node n2; n2.character = 'a'; s.push(n2);
//     Node n3; n3.boolean = 0; s.push(n3);
//     cout << s.pop().boolean << endl;
//     cout << s.pop().character << endl;
//     cout << s.pop().integer << endl;
// }