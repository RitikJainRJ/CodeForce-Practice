/*
Kuriyama Mirai has killed many monsters and got many (namely n) stones. She numbers the stones from 1 to n.
The cost of the i-th stone is vi. Kuriyama Mirai wants to know something about these stones so she will
ask you two kinds of questions:

She will tell you two numbers, l and r (1≤l≤r≤n), and you should tell her .
Let ui be the cost of the i-th cheapest stone (the cost that will be on the i-th place if we arrange
all the stone costs in non-decreasing order).
time she will tell you two numbers, l and r (1≤l≤r≤n), and you should tell her .

For every question you should give the correct answer, or Kuriyama Mirai will say "fuyukai desu"
and then become unhappy.
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;


// using prefix Sum.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;

    cin >> n;
    ll arr[n], sort_arr[n];
    for(int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        arr[i] = temp;
        sort_arr[i] = temp;
    }
    sort(sort_arr, sort_arr + n);
    cin >> m;
    for(int i = 1; i < n; i++){
        arr[i] = arr[i - 1] + arr[i];
        sort_arr[i] = sort_arr[i - 1] + sort_arr[i];
    }
    while(m--){
        int t, l, r;
        ll sum;
        cin >> t >> l >> r;
        l--;
        r--;
        if(t == 1){
            if(l - 1 >= 0)
                sum = arr[r] - arr[l - 1];
            else
                sum = arr[r];
            cout << sum << endl;
        }
        else if(t == 2){
            if(l - 1 >= 0)
                sum = sort_arr[r] - sort_arr[l - 1];
            else
                sum = sort_arr[r];
            cout << sum << endl;
        }
    }
    return 0;
}
