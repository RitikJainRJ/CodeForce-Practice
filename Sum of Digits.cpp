/*
Having watched the last Harry Potter film, little Gerald also decided to practice magic.
He found in his father's magical book a spell that turns any number in the sum of its digits.
At the moment Gerald learned that, he came across a number n. How many times can Gerald put a spell
on it until the number becomes one-digit?
*/
#include<bits/stdc++.h>
using namespace std;

int main(void){
    string n;
    int temp, count = 0;

    cin >> n;
    if(n.length() == 1){
        cout << count << endl;
        return 0;
    }
    while(n.length() != 1){
        count++;
        temp = 0;
        for(int i = 0; i < n.length(); i++)
            temp += (n[i] - '0');
        n = to_string(temp);
    }
    cout << count << endl;
    return 0;
}
