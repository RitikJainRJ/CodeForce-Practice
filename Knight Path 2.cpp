#include<bits/stdc++.h>
using namespace std;

struct cell{
    int x, y, d;
    cell(){}
    cell(int x, int y, int d) : x(x), y(y), d(d){}
};

int knightPath(int);
bool isSafe(int, int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << knightPath(n) << endl;
    }
    return 0;
}

int knightPath(int n){
    int kx, ky, tx, ty;
    bool visited[n][n];
    queue<cell> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = false;
    cin >> kx >> ky >> tx >> ty;
    kx--;
    ky--;
    tx--;
    ty--;
    visited[kx][ky] = true;
    q.push(cell(kx, ky, 0));
    while(!q.empty()){
        cell temp = q.front();
        q.pop();
        if(temp.x == tx && temp.y == ty)
            return temp.d;
        int xmove[] = {-2, -2, -1, -1, 2, 2, 1, 1};
        int ymove[] = {1, -1, 2, -2, 1, -1, 2, -2};
        for(int i = 0; i < 8; i++){
            int _x = temp.x + xmove[i];
            int _y = temp.y + ymove[i];
            if(isSafe(_x, _y, n) && visited[_x][_y] == false){
                visited[_x][_y] = true;
                q.push(cell(_x, _y, temp.d + 1));
            }
        }
    }
}

bool isSafe(int x, int y, int n){
    if(0 <= x && x < n && 0 <= y && y < n)
        return true;
    return false;
}
