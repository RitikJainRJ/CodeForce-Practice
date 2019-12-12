/*
A burglar got into a matches warehouse and wants to steal as many matches as possible.
In the warehouse there are m containers, in the i-th container there are ai matchboxes,
and each matchbox contains bi matches. All the matchboxes are of the same size.
The burglar's rucksack can hold n matchboxes exactly. Your task is to find out the maximum amount
of matches that a burglar can carry away. He has no time to rearrange matches in the matchboxes,
that's why he just chooses not more than n matchboxes so that the total amount of matches in them is maximal.
*/
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, m, result = 0;
    map<int, vector<int>, greater<int>> om;
    map<int, vector<int>, greater<int>>::iterator it;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        om[b].push_back(a);
    }
    for(it = om.begin(); it != om.end(); it++){
        for(int i = 0; i < it->second.size(); i++){
            if(n >= it->second[i]){
                n -= it->second[i];
                result += (it->second[i] * it->first);
            }
            else{
                result += (it->first * n);
                cout << result << endl;
                return 0;
            }
        }
    }
    cout << result << endl;
    return 0;
}
