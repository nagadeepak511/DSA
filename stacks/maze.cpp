#include "stacks.cpp"

void display(int a[]){
    for(int i=0; i<10; i++) cout << a[i] << " ";
    cout << endl;
}

void pathFinder(int a[50][50], int n, Stack path, int start[2]){
    int x = path.peek()%n, y=path.peek()/n;
    if(x == start[0] && y == start[1]) return;
    else if(!(a[x+1][y] || a[x-1][y] || a[x][y-1] || a[x][y+1])){
        a[x][y] = 0;
        path.pop();
    }
    else{
        a[x][y] = 0;
        if(a[x+1][y]){
            path.push(a[x+1][y]);
            pathFinder(a, n, path, start);
        }
        else if(a[x-1][y]){
            path.push(a[x-1][y]);
            pathFinder(a, n, path, start);
        }
        else if(a[x][y+1]){
            path.push(a[x][y+1]);
            pathFinder(a, n, path, start);
        }
        else if(a[x][y-1]){
            path.push(a[x][y-1]);
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

    display(path.elements);
}