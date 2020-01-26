#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int m = n / 2, temp = arr[m] - arr[0];
    for(int i = 0; i < m; i++){
        if(arr[i] == arr[m])
            continue;
        else if(arr[i] + temp == arr[m])
            continue;
        else{
            cout << "NO";
            return 0;
        }
    }
    temp = arr[n - 1] - arr[m];
    for(int i = m + 1; i < n; i++){
        if(arr[i] == arr[m])
            continue;
        else if(arr[i] - temp == arr[m])
            continue;
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
