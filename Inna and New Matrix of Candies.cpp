#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;

    cin >> n >> m;
    char arr[n][m];
    unordered_set<int> us;

    for(int i = 0; i < n; i++){
        int s, e;
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'G')
                s = j;
            if(arr[i][j] == 'S')
                e = j;
        }
        int x = e - s;
        if(x < 0){
            cout << -1 << endl;
            return 0;
        }
        if(us.find(x) == us.end() && x != 0)
            us.insert(x);
    }
    cout << us.size() << endl;
    return 0;
}
