#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll x0, y0, x1, y1, n, r, a, b;
    ll xmove[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    ll ymove[] = {0, 1, 1, 1, 0, -1, -1, -1};
    map<pair<ll, ll>, ll> om;
    queue<pair<ll, ll>> q;

    cin >> x0 >> y0 >> x1 >> y1 >> n;
    for(ll i = 0; i < n; i++){
        cin >> r >> a >> b;
        for(ll j = a; j <= b; j++)
            om[{r, j}] = -1;
    }
    om[{x0, y0}] = 0;
    q.push({x0, y0});
    while(!q.empty()){
        pair<ll, ll> temp = q.front();
        q.pop();
        if(temp.first == x1 && temp.second == y1){
            cout << om[temp];
            return 0;
        }
        for(ll i = 0; i < 8; i++){
            ll _x = temp.first + xmove[i];
            ll _y = temp.second + ymove[i];
            if(om.find({_x, _y}) != om.end() && om[{_x, _y}] == -1){
                om[{_x, _y}] = om[temp] + 1;
                q.push({_x, _y});
            }
        }
    }
    cout << -1;
    return 0;
}
