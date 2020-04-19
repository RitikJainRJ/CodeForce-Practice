#include<bits/stdc++.h>
using namespace std;

int main(){
    double n, t1, t2, k, i = 1, a, b;
    multimap<double, double, greater<double>> um;

    cin >> n >> t1 >> t2 >> k;
    while(n--){
        cin >> a >> b;
        double temp1 = (a * t1) + (b * t2) - ((a * t1) * (k / 100));
        double temp2 = (b * t1) + (a * t2) - ((b * t1) * (k / 100));
        if(temp1 > temp2)
            um.insert({temp1, i});
        else
            um.insert({temp2, i});
        i++;
    }
    for(auto it = um.begin(); it != um.end(); it++)
        cout << fixed << setprecision(0) << it->second << " " << fixed << setprecision(2) << it->first << endl;
    return 0;
}
