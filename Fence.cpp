/*
here is a fence in front of Polycarpus's home. The fence consists of n planks of the same width which go one
after another from left to right. The height of the i-th plank is hi meters, distinct planks can have distinct
heights.
Fence for n=7 and h=[1,2,6,1,1,7,1]

Polycarpus has bought a posh piano and is thinking about how to get it into the house.
In order to carry out his plan, he needs to take exactly k consecutive planks from the fence.
Higher planks are harder to tear off the fence, so Polycarpus wants to find such k consecutive
planks that the sum of their heights is minimal possible.

Write the program that finds the indexes of k consecutive planks with minimal total height.
Pay attention, the fence is not around Polycarpus's home, it is in front of home
(in other words, the fence isn't cyclic).
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, min = INT_MAX, res;

    cin >> n >> k;
    vector<ll> vec, store(n, 0);
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        vec.push_back(temp);
    }
    ll temp = 0;
    for(ll i = n - k; i < n; i++)
        temp += vec[i];
    store[n - k] = temp;
    min = store[n - k];
    res = n - k;
    for(ll i = n - k - 1; i >= 0; i--){
        store[i] = vec[i] + store[i + 1] - vec[i + k];
        if(store[i] < min){
            min = store[i];
            res = i;
        }
    }
    cout << res + 1 << endl;
    return 0;
}
