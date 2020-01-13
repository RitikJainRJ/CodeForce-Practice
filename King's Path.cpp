#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

map<pair<int, int>, int> um;

int main(){
    int x0, y0, x1, y1, n;
    queue<pair<int, int>> q;

    cin >> x0 >> y0 >> x1 >> y1 >> n;
    x0--;
    y0--;
    x1--;
    y1--;
    for(int i = 0; i < n; i++){
        int r, a, b;
        cin >> r >> a >> b;
        r--;
        a--;
        b--;
        for(int j = a; j <= b; j++)
            um[{a, b}] = -1;
    }
    um[{x0, y0}] = 0;
    q.push({x0, y0});
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int d = um[temp];
        if(temp.first == x1 && temp.second == y1){
            cout << d;
            return 0;
        }
        int xmove[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int ymove[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for(int i = 0; i < 8; i++){
            int _x = temp.first + xmove[i];
            int _y = temp.second + ymove[i];
            pair<int, int> t = {_x, _y};
            if(um.find(t) != um.end() && um[t] == -1){
                um[t] = d + 1;
                q.push(t);
            }
        }
    }
    cout << -1;
    return 0;
}
