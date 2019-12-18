/*
Vanya walks late at night along a straight street of length l, lit by n lanterns.
Consider the coordinate system with the beginning of the street corresponding to the point 0,
and its end corresponding to the point l. Then the i-th lantern is at the point ai.
The lantern lights all points of the street that are at the distance of at most d from it,
where d is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?
*/
#include<bits/stdc++.h>
#define ld long double
#define ll unsigned long long
using namespace std;

// no array can be of 10^9 digits long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ld> vec;
    ll n, l;
    ld res = 0;
    cin >> n >> l;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    for(ll i = 1; i < n; i++)
        res = max(res, vec[i] - vec[i - 1]);
    res = max(res, vec[0] * 2);
    res = max(res, (l - vec[n - 1]) * 2);
    cout << fixed << setprecision(10) << res / 2 << endl;
    return 0;
}
