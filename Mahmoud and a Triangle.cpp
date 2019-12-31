/*
Mahmoud has n line segments, the i-th of them has length ai. Ehab challenged him to use exactly 3
line segments to form a non-degenerate triangle. Mahmoud doesn't accept challenges unless he is sure he
can win, so he asked you to tell him if he should accept the challenge. Given the lengths of the line segments,
check if he can choose exactly 3 of them to form a non-degenerate triangle.

Mahmoud should use exactly 3 line segments, he can't concatenate two line segments or change any length.
A non-degenerate triangle is a triangle with positive area.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n - 2; i++){
        if(arr[i] + arr[i + 1] > arr[i + 2]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
