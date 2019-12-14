/*
Calculate
R := BP mod M
for large values of B, P, and M using an efficient algorithm. (That’s right, this problem has a time
dependency !!!.)
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll bigMod(ll, ll, ll);

int main(void){
    ll t, b, p, m;

    cin >> t;
    while(t--){
        cin >> b >> p >> m;
        cout << bigMod(b, p, m) << endl << endl;
    }
    return 0;
}

ll bigMod(ll b, ll p, ll m){
    if(p == 1)
        return b;
    else if(p == 0)
        return 1;
    else{
        ll temp = (bigMod(b, p / 2, m) % m);
        if(p % 2 == 0)
            return (temp * temp) % m;
        else
            return (b * ((temp * temp) % m)) % m;
    }
}
