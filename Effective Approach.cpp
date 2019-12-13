/*
Vasya believes that a linear search would work better if it sequentially iterates through the elements,
starting with the 1-st one (in this problem we consider the elements of the array indexed from 1 to n)
and ending with the n-th one. And Petya says that Vasya is wrong: the search will need less comparisons
if it sequentially iterates the elements starting from the n-th and ending with the 1-st one.
Sasha argues that the two approaches are equivalent.
But the problem is, linear search is too slow. That's why the boys aren't going to find out who is
right before the end of the training, unless you come in here. Help them to determine who will win the
dispute.
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(void){
    ll n, q, vcomp = 0, pcomp = 0;
    unordered_map<ll, ll> um;

    cin >> n;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        um[temp] = i + 1;
    }
    cin >> q;
    for(ll i = 0; i < q; i++){
        ll x;
        cin >> x;
        vcomp += um[x];
        pcomp += (n - um[x] + 1);
    }
    cout << vcomp << " " << pcomp << endl;
    return 0;
}
