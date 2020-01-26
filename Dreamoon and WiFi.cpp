/*
Dreamoon is standing at the position 0 on a number line. Drazil is sending a list of commands through Wi-Fi
to Dreamoon's smartphone and Dreamoon follows them.

Each command is one of the following two types:

Go 1 unit towards the positive direction, denoted as '+'
Go 1 unit towards the negative direction, denoted as '-'

But the Wi-Fi condition is so poor that Dreamoon's smartphone reports some of the commands can't be
recognized and Dreamoon knows that some of them might even be wrong though successfully recognized.
Dreamoon decides to follow every recognized command and toss a fair coin to decide those unrecognized ones
(that means, he moves to the 1 unit to the negative or positive direction with the same probability 0.5).

You are given an original list of commands sent by Drazil and list received by Dreamoon.
What is the probability that Dreamoon ends in the position originally supposed to be final by Drazil's
commands?
*/
#include<bits/stdc++.h>
using namespace std;

void findProb(int&, int, string, int, int);

int main(){
    string s1, s2;
    int sum = 0, c = 0, res;

    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++)
        sum += (s1[i] == '+') ? 1 : -1;
    findProb(res, 0, s2, 0, sum);
    for(int i = 0; i < s2.length(); i++)
        c += (s2[i] == '?') ? 1 : 0;
    cout << fixed << setprecision(12) << (float)(res) / pow(2, c);
    return 0;
}

void findProb(int &res, int temp, string str, int index, int sum){
    if(index == str.length()){
        if(temp == sum)
            res++;
        return;
    }
    if(str[index] == '+')
        findProb(res, temp + 1, str, index + 1, sum);
    else if(str[index] == '-')
        findProb(res, temp - 1, str, index + 1, sum);
    else{
        findProb(res, temp + 1, str, index + 1, sum);
        findProb(res, temp - 1, str, index + 1, sum);
    }
}
