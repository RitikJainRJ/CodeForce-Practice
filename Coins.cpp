/*
The input data contains the results of all the weighting, one result on each line.
It is guaranteed that every coin pair was weighted exactly once.
Vasya labelled the coins with letters «A», «B» and «C». Each result is a line that appears as (letter)
(> or < sign)(letter). For example, if coin "A" proved lighter than coin "B", the result of the weighting
is A<B.
*/#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s1, s2, s3;
    map<char, int> om;
    map<char, int>::iterator it;

    om['A'] = 0;
    om['B'] = 0;
    om['C'] = 0;
    cin >> s1 >> s2 >> s3;
    if(s1[1] == '>') om[s1[0]]++;
    else    om[s1[2]]++;
    if(s2[1] == '>') om[s2[0]]++;
    else    om[s2[2]]++;
    if(s3[1] == '>') om[s3[0]]++;
    else    om[s3[2]]++;

    if(om['A'] == om['B'] || om['B'] == om['C'] ){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 0; i < 3; i++)
        for(it = om.begin(); it != om.end(); it++)
            if(it->second == i)
                cout << it->first;
    cout << endl;
    return 0;
}
