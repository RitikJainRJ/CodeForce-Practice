#include<bits/stdc++.h>
using namespace std;

bool isWin(char arr[3][3], int i, int j, char ch){
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
        if(resD == true)
            return true;
        resD = true;
        for(int k = 0; k < 3; k++)
            if(arr[k][2 - k] != ch)
                resD = false;
        if(resD == true)
            return true;
    }
    return false;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        char arr[3][3];
        int countX = 0, countO = 0;
        bool winX = false, winO = false;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'X')
                    countX++;
                if(arr[i][j] == 'O')
                    countO++;
            }
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                if(arr[i][j] == 'X' && isWin(arr, i, j, 'X'))
                    winX = true;
                if(arr[i][j] == 'O' && isWin(arr, i, j, 'O'))
                    winO = true;
            }
        if(winX && winO){
            cout << "Invalid" << endl;
            continue;
        }
        if(winX && countX == countO + 1){
            cout << "Valid" << endl;
            continue;
        }
        if(winO && countX == countO){
            cout << "Valid" << endl;
            continue;
        }
        if((!winO && !winX) && (countX == countO || countX == countO + 1)){
            cout << "Valid" << endl;
            continue;
        }
        cout << "Invalid" << endl;
    }
    return 0;
}
