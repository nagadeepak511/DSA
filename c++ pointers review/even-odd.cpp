#include<iostream>
using namespace std;

void display(int*a, int n){
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n=0, a[100];
    char c[100]; cin.get(c,100);
    int i=0, val=0;
    while(c[i] != '\0'){
        while(c[i] >= '0' && c[i] <= '9'){ 
            val = val*10 + (c[i]-'0');
            if(c[++i] == ' ' || c[i] == '\0') {
                a[n++] = val;
                val=0;
            }
        }
        i++;
    }

    int *lptr=a, *rptr=a+(n-1);

    while(lptr!=rptr){
        while((*lptr)%2==0) lptr++;
        while((*rptr)%2!=0) rptr--;
        if(lptr > rptr) break;
        int temp = *lptr;
        *lptr = *rptr;
        *rptr = temp;
    }

    display(a,n);

    
}