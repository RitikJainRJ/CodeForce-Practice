#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int maxTrees(int, int[], int[], int);

int main(){
    int n;

    cin >> n;
    int x[n], h[n];

    for(int i = 0; i < n; i++)
        cin >> x[i] >> h[i];
    cout << maxTrees(n - 1, x, h, MAX) << endl;
    return 0;
}

int maxTrees(int index, int x[], int h[], int r){
    if(index == 0){
        int a = 0, b = 0, c = 0;
        b = 1;
        if(x[index] + h[index] < r)
            c = 1;
        return max({a, b, c});
    }
    int a = 0, b = 0, c = 0;
    a = maxTrees(index - 1, x, h, x[index]);
    if(x[index - 1] < x[index] - h[index])
        b = 1 + maxTrees(index - 1, x, h, x[index] - h[index]);
    if(x[index] + h[index] < r)
        c = 1 + maxTrees(index - 1, x, h, x[index]);
    return max({a, b, c});
}
