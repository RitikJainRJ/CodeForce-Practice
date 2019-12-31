/*
tic Tac Toe is a child's game played on a 3 by 3 grid. One player, X, starts by placing an X at an unoccupied
grid position. Then the other player, O, places an O at an unoccupied grid position. Play alternates between X
and O until the grid is filled or one player's symbols occupy an entire line (vertical, horizontal,
or diagonal) in the grid.


We will denote the initial empty Tic Tac Toe grid with nine dots. Whenever X or O plays we fill in an X or
an O in the appropriate position. The example below illustrates each grid configuration from the beginning
to the end of a game in which X wins.
*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(char arr[3][3], int i, int j, char ch){
    bool resR = true, resC = true, resD = true;
    for(int k = 0; k < 3; k++){
        if(arr[i][k] != ch)
            resR = false;
    }
    if(resR == true)
        return true;
    for(int k = 0; k < 3; k++){
        if(arr[k][j] != ch)
            resC = false;
    }
    if(resC == true)
        return true;
    if(i == 1 && j == 1){
        for(int k = 0; k < 3; k++)
            if(arr[k][k] != ch)
                resD = false;
        for(int k = 0; k < 3; k++)
            if(arr[k][2 - k] != ch)
                resD = false;
        if(resD == true)
            return true;
    }
    return false;
}

int main(){
    int n;

    cin >> n;
    while(n--){
        char arr[3][3];
        int countX = 0, countO = 0;
        bool flagX = false, flagO = false;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'X')
                    countX++;
                if(arr[i][j] == 'O')
                    countO++;
            }
        if(countX == countO || countX == countO + 1){
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++){
                    if(arr[i][j] == 'X' && isSafe(arr, i, j, 'X'))
                        flagX = true;
                    if(arr[i][j] == 'O' && isSafe(arr, i, j, 'O'))
                        flagO = true;
                }
            if(flagX && flagO)
                cout << "no" << endl;
            else{
                if(flagO && countX == countO){
                    cout << "yes" << endl;
                    continue;
                }
                if(flagX && countX == countO + 1){
                    cout << "yes" << endl;
                    continue;
                }
                cout << "no" << endl;
            }
        }
        else
            cout << "no" << endl;
    }
    return 0;
}
