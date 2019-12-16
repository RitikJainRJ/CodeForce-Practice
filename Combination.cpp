/*
Computing the exact number of ways that N things can be taken M at a time can be a great challenge
when N and/or M become very large. Challenges are the stuff of contests. Therefore, you are to make
just such a computation given the following:
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll c[101][101];

ll combination(ll, ll);

int main(void){
    ll n, r;

    memset(c, -1, sizeof(c));
    cin >> n >> r;
    cout << combination(n, r) << endl;
    return 0;
}

ll combination(ll n, ll r){
    if(n == r)
        return 1;
    if(r == 0)
        return 1;
    if(c[n][r] != -1)
        return c[n][r];

    c[n][r] = combination(n - 1, r) + combination(n - 1, r - 1);
    return c[n][r];
}
