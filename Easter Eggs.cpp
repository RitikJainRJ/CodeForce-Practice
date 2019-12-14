/*
The Easter Rabbit laid n eggs in a circle and is about to paint them.

Each egg should be painted one color out of 7: red, orange, yellow, green, blue, indigo or violet.
Also, the following conditions should be satisfied:

Each of the seven colors should be used to paint at least one egg.
Any four eggs lying sequentially should be painted different colors.

Help the Easter Rabbit paint the eggs in the required manner. We know that it is always possible.
*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(string, string, char);

int main(){
    int n;
    char arr[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    string res;

    cin >> n;
    for(int i= 0; i < 7; i++)
        res += arr[i];
    for(int i = 7; i < n; i++){
        string temp1 = res.substr(i - 3, 3);
        string temp2 = res.substr(0, 3);
        for(int j = 0; j < 7; j++){
            if(isSafe(temp1, temp2, arr[j])){
                res += arr[j];
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}

bool isSafe(string str1, string str2, char a){
    for(int i = 0; i < str1.length(); i++)
        if(str1[i] == a)
            return false;
    for(int i = 0; i < str2.length(); i++)
        if(str2[i] == a)
            return false;
    return true;
}
