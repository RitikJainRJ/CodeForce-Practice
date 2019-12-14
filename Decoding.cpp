/*
Polycarp is mad about coding, that is why he writes Sveta encoded messages.
He calls the median letter in a word the letter which is in the middle of the word.
If the word's length is even, the median letter is the left of the two middle letters.
In the following examples, the median letter is highlighted: contest, info.
If the word consists of single letter, then according to above definition this letter is the median letter.

Polycarp encodes each word in the following way: he writes down the median letter of the word,
then deletes it and repeats the process until there are no letters left. For example,
he encodes the word volga as logva.

You are given an encoding s of some word, your task is to decode it.
*/
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, flag  = 0;
    string str, res;

    cin >> n >> str;
    if(n % 2 != 0){
        for(int i = 0; i < str.length(); i++){
            if(flag == 0){
                res.push_back(str[i]);
                flag = 1;
            }
            else{
                res.insert(res.begin(), str[i]);
                flag = 0;
            }
        }
    }
    else{
        for(int i = 0; i < str.length(); i++){
            if(flag == 0){
                res.insert(res.begin(), str[i]);
                flag = 1;
            }
            else{
                res.push_back(str[i]);
                flag = 0;
            }
        }
    }
    cout << res << endl;
}
