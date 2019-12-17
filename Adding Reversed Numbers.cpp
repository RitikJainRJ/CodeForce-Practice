/*
Reversed number is a number written in Arabic numerals but the order of digits is reversed. The
first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the
tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the
number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed
number never has any trailing zeros.
ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and
output their reversed sum. Of course, the result is not unique because any particular number is a
reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must
assume that no zeros were lost by reversing (e.g. assume that the original number was 12)
*/
#include<bits/stdc++.h>
using namespace std;

void sumString(string, string);

int main(void){
    int t;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        sumString(s1, s2);
        cout << endl;
    }
    return 0;
}

void sumString(string s1, string s2){
    int l1, l2, c = 0;
    string res;

    if(s1.length() < s2.length())
        swap(s1, s2);
    l1 = s1.length();
    l2 = s2.length();
    for(int i = 0; i < l2; i++){
        int sum = (s1[i] - '0') + (s2[i] - '0') + c;
        res.push_back((sum % 10) + '0');
        c = sum / 10;
    }
    for(int i = l2; i < l1; i++){
        int sum = (s1[i] - '0') + c;
        res.push_back((sum % 10) + '0');
        c = sum / 10;
    }
    if(c > 0)
        res.push_back(c + '0');
    while(1){
        if(res[0] == '0')
            res.erase(res.begin());
        else
            break;
    }
    cout << res;
}
