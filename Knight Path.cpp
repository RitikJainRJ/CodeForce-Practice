/*recursive*/
#include<bits/stdc++.h>
using namespace std;

int knightPath(int);
void _knightPath(int**, int, int, int, int, int[], int[], int, int&, int);
bool isSafe(int, int, int**, int);

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
    int **arr = new int*[n];
    int kx, ky, tx, ty, counter = 1, res = INT_MAX;
    int x_move[] = {2, 2, -2, -2, 1, -1, 1, -1};
    int y_move[] = {1, -1, 1, -1, 2, 2, -2, -2};

    for(int i = 0; i < n; i++)
        arr[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = -1;
    cin >> kx >> ky >> tx >> ty;
    kx--;
    ky--;
    tx--;
    ty--;
    arr[kx][ky] = 0;
    _knightPath(arr, kx, ky, tx, ty, x_move, y_move, counter, res, n);
    return res;
}

void _knightPath(int **arr, int x, int y, int tx, int ty, int x_move[], int y_move[], int counter, int &res, int n){
    if(x == tx && y == ty){
        if(res > counter - 1)
            res = counter - 1;
        return;
    }
    if(res <= counter - 1)
        return;
    for(int i = 0; i < 8; i++){
        int _x = x + x_move[i];
        int _y = y + y_move[i];
        if(isSafe(_x, _y, arr, n)){
            arr[_x][_y] = counter;
            _knightPath(arr, _x, _y, tx, ty, x_move, y_move, counter + 1, res, n);
            arr[_x][_y] = -1;
        }
    }
}

bool isSafe(int x, int y, int **arr, int n){
    if(0 <= x && x < n && 0 <= y && y < n && arr[x][y] == -1)
        return true;
    return false;
}
