/*
Shop, where Noora is working, has a plan on the following n days. For each day sales manager knows exactly,
that in i-th day ki products will be put up for sale and exactly li clients will come to the shop that day.
Also, the manager is sure, that everyone, who comes to the shop, buys exactly one product or, if there aren't
any left, leaves the shop without buying anything. Moreover, due to the short shelf-life of the products,
manager established the following rule: if some part of the products left on the shelves at the end of the day,
that products aren't kept on the next day and are sent to the dump.

For advertising purposes manager offered to start a sell-out in the shop.
He asked Noora to choose any f days from n next for sell-outs. On each of f chosen days the number of
products were put up for sale would be doubled. Thus, if on i-th day shop planned to put up for sale ki
products and Noora has chosen this day for sell-out, shelves of the shop would keep 2·ki products.
Consequently, there is an opportunity to sell two times more products on days of sell-out.

Noora's task is to choose f days to maximize total number of sold products. She asks you to help
her with such a difficult problem.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, f, res = 0;
    multimap<ll, ll, greater<ll>> omm;
    multimap<ll, ll, greater<ll>>::iterator it;

    cin >> n >> f;
    ll k[n], l[n], visited[n];
    memset(visited, 0, sizeof(visited));
    for(ll i = 0; i < n; i++)
        cin >> k[i] >> l[i];
    for(ll i = 0; i < n; i++){
        if(k[i] >= l[i])
            continue;
        ll a, b, c;
        a = k[i];
        b = k[i] * 2;
        if(b > l[i])
            b = l[i];
        c = b - a;
        omm.insert({c, i});
    }
    for(it = omm.begin(); it != omm.end() && f > 0; it++, f--){
        ll index = it->second;
        ll temp = k[index] * 2;
        if(temp > l[index])
            temp = l[index];
        res += temp;
        visited[index] = 1;
    }
    for(ll i = 0; i < n; i++){
        if(visited[i] == 1)
            continue;
        ll temp;
        if(k[i] > l[i])
            temp = l[i];
        if(k[i] <= l[i])
            temp = k[i];
        res += temp;
    }
    cout << res << endl;
    return 0;
}
