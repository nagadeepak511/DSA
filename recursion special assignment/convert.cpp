#include<iostream>
using namespace std;

void convert(int n, int b){
    if(n == 0) cout << 0;
    else{
        convert(n/b, b);
        if(n%b < 10)
            cout << n%b;
        else{
            char c = 'A' + n%b-10;
            cout << c;
        }
    }
}

int main(){
    int n,b; cin >> n >> b;
    convert(n,b) ;
}