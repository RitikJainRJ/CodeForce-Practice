/*
Fox Ciel saw a large field while she was on a bus. The field was a n×m rectangle divided into 1×1 cells.
Some cells were wasteland, and other each cell contained crop plants: either carrots or kiwis or grapes.

After seeing the field carefully, Ciel found that the crop plants of each cell were planted in following
procedure:

    Assume that the rows are numbered 1 to n from top to bottom and the columns are numbered 1 to m from
    left to right, and a cell in row i and column j is represented as (i,j).
    First, each field is either cultivated or waste. Crop plants will be planted in the cultivated cells in
    the order of (1, 1) → ... → (1, m) → (2, 1) → ... → (2, m) → ... → (n, 1) → ... → (n, m). Waste cells will
    be ignored.
    Crop plants (either carrots or kiwis or grapes) will be planted in each cell one after another cyclically.
    Carrots will be planted in the first cell, then kiwis in the second one, grapes in the third one, carrots
    in the forth one, kiwis in the fifth one, and so on.

The following figure will show you the example of this procedure. Here, a white square represents a cultivated
cell, and a black square represents a waste cell.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k, t;
    set<ll> os;

    cin >> n >> m >> k >> t;
    while(k--){
        ll a, b, c;
        cin >> a >> b;
        c = (a - 1) * m + b;
        os.insert(c);
    }
    while(t--){
        ll a, b, c;
        cin >> a >> b;
        c = (a - 1) * m + b;
        if(os.find(c) != os.end())
            cout << "Waste" << endl;
        else{
            ll temp = 0;
            for(auto it = os.begin(); it != os.end(); it++){
                if(*it <= c)
                    temp++;
                else
                    break;
            }
            temp++;
            temp = (c - temp) % 3;
            switch(temp){
                case 0: cout << "Carrots" << endl;
                        break;
                case 1: cout << "Kiwis" << endl;
                        break;
                case 2: cout << "Grapes" << endl;
                        break;
            }
        }
    }
    return 0;
}
