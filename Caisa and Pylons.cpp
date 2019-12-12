/*
Caisa is playing a mobile game during his path. There are (n + 1) pylons numbered from 0 to n in this game.
The pylon with number 0 has zero height, the pylon with number i (i > 0) has height hi.
The goal of the game is to reach n-th pylon, and the only move the player can do is to jump from the
current pylon (let's denote its number as k) to the next one (its number will be k + 1).
When the player have made such a move, its energy increases by hk - hk + 1 (if this value is negative
the player loses energy). The player must have non-negative amount of energy at any moment of the time.

Initially Caisa stand at 0 pylon and has 0 energy. The game provides a special opportunity:
one can pay a single dollar and increase the height of anyone pylon by one. Caisa may use that
opportunity several times, but he doesn't want to spend too much money. What is the minimal amount
of money he must paid to reach the goal of the game?
*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, m = 0, e = 0;    // m is money and e is extra energy.

    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    m += arr[0];
    for(int i = 0; i < n - 1; i++){
        if(arr[i] < arr[i + 1]){
            int temp = arr[i + 1] - arr[i];
            if(e >= temp){
                e -= temp;
            }
            else{
                m += (temp - e);
                e = 0;
            }
        }
        else{
            e += arr[i] - arr[i + 1];
        }
    }
    cout << m << endl;
    return 0;
}
