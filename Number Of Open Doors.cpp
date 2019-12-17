/*
Consider a long alley with a N number of doors on one side. All the doors are closed initially.
You move to and fro in the alley changing the states of the doors as follows:
you open a door that is already closed and you close a door that is already opened.
You start at one end go on altering the state of the doors till you reach the other end and then
you come back and start altering the states of the doors again.

In the first go, you alter the states of doors numbered 1, 2, 3, … , n.
In the second go, you alter the states of doors numbered 2, 4, 6 …
In the third go, you alter the states of doors numbered 3, 6, 9 …
You continue this till the Nth go in which you alter the state of the door numbered N.
You have to find the number of open doors at the end of the procedure.
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll openDoor(ll);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << openDoor(n) << endl;
    }
    return 0;
}

ll openDoor(ll n){
    ll count = 0;

    for(ll i = 1; i <= n; i++){
        ll temp = sqrt(i);
        if((temp * temp) == i)
            count++;
    }
    return count;
}
