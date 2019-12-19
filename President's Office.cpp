/*
President of Berland has a very vast office-room, where, apart from him, work his subordinates.
Each subordinate, as well as President himself, has his own desk of a unique colour.
Each desk is rectangular, and its sides are parallel to the office walls. One day President decided to
establish an assembly, of which all his deputies will be members. Unfortunately, he does not remember
the exact amount of his deputies, but he remembers that the desk of each his deputy is adjacent to his own
desk, that is to say, the two desks (President's and each deputy's) have a common side of a positive length.

The office-room plan can be viewed as a matrix with n rows and m columns.
Each cell of this matrix is either empty, or contains a part of a desk.
An uppercase Latin letter stands for each desk colour. The «period» character («.») stands for an empty cell.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    char ch;
    unordered_set<char> us;

    cin >> n >> m >> ch;
    char arr[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    int x_move[] = {-1, 0, 1, 0};
    int y_move[] = {0, 1, 0, -1};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(arr[i][j] == ch){
                for(int k = 0; k < 4; k++){
                    int _x = i + x_move[k];
                    int _y = j + y_move[k];
                    if(0 <= _x && _x < n && 0 <= _y && _y < m)
                        if(arr[_x][_y] != ch && arr[_x][_y] != '.')
                            us.insert(arr[_x][_y]);
                }
            }
        }
    cout << us.size() << endl;
    return 0;
}
