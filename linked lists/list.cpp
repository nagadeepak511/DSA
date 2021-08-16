#include<iostream>
using namespace std;

class Node{
public:
    int value; Node *next, * prev;
    
    Node(int v, Node *p=NULL, Node *n=NULL){
        value = v;
        prev = p;
        next = n;
    }
};

class List{
public:
    Node *head=NULL;
    
};

int main(){

}