#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    int arr[2][n];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 0){
            arr[0][i] = 0;
            arr[1][i] = 0;
        }
        else if(a == 1){
            arr[0][i] = 0;
            arr[1][i] = 1;
        }
        else if(a == 2){
            arr[0][i] = 1;
            arr[1][i] = 0;
        }
        else if(a == 3){
            arr[0][i] = 1;
            arr[1][i] = 1;
        }
    }
    for(int i = 1; i < n; i++){
        arr[0][i] += arr[1][i - 1];
        arr[1][i] += arr[0][i - 1];
    }
    int temp = max(arr[0][n - 1], arr[1][n - 1]);
    cout << n - temp << " ";
    return 0;
}
