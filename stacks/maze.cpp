#include "stacks.cpp"

void display(Stack a, int n){
    while(a.top > -1){
        cout << a.peek()%n << " " << a.peek()/n << endl;
        a.pop();
    }
}

void pathFinder(int a[50][50], int n, Stack &path, int start[2]){ 
    int x = path.peek()%n, y=path.peek()/n;
    int top = path.pop();
    int prev;
    if(path.top > -1) prev = path.peek();
    path.push(top);

    //display(path, n);
    //cout << endl;
    //cout << endl;

    if(x == start[0] && y == start[1]) return;
    else{
        if(a[x+1][y] && (path.top == 0 || x+1+y*n != prev)){
            path.push(x+1+y*n);
            pathFinder(a, n, path, start);
        }
        else if(a[x-1][y] && (path.top == 0 || x-1+y*n != prev)){
            path.push(x-1+(y)*n);
            pathFinder(a, n, path, start);
        }
        else if(a[x][y+1] && (path.top == 0 || x+(y+1)*n != prev)){
            path.push(x+(y+1)*n);
            pathFinder(a, n, path, start);
        }
        else if(a[x][y-1] && (path.top == 0 || x+(y-1)*n != prev)){
            path.push(x+(y-1)*n);
            pathFinder(a, n, path, start);
        }
        else {
            path.pop();
            a[x][y] = 0;
            pathFinder(a, n, path, start);
        }
    }
}

int main(){
    int n; cin >> n;
    int a[50][50];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> a[i][j];
    }
    int start[2], end[2];
    for(int i=0; i<2; i++) cin >> start[i];
    for(int i=0; i<2; i++) cin >> end[i];
    Stack path; path.push(end[0]+n*end[1]);
    pathFinder(a, n, path, start);

    display(path, n);
}