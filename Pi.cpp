/*
Given any pair of whole numbers chosen from a large, random collection of numbers, the
probability that the two numbers have no common factor other than one (1) is 6/2π
For example, using the small collection of numbers: 2, 3, 4, 5, 6; there are 10 pairs that can be
formed: (2,3), (2,4), etc. Six of the 10 pairs: (2,3), (2,5), (3,4), (3,5), (4,5) and (5,6) have no common
factor other than one. Using the ratio of the counts as the probability we have:
6/2π ≈ 6/10
π ≈ 3.162
In this problem, you will receive a series of data sets. Each data set contains a set of pseudo-random
positive integers. For each data set, find the portion of the pairs which may be formed that have
no-common factor other than one (1), and use the method illustrated above to obtain an estimate for
π. Report this estimate for each data set.
*/
#include<bits/stdc++.h>
#define ld long double
using namespace std;

bool isCoPrime(int, int);
ld findCoPrime(vector<ld>);

int main(void){
    int a;

    while(1){
        cin >> a;
        if(a == 0)
            break;
        else{
            vector<ld> vec;
            ld p, n = 0, tp, res, temp;

            while(a--){
                cin >> temp;
                vec.push_back(temp);
                n++;
            }
            p = findCoPrime(vec);
            if(p == 0){
                cout << "No estimate for this data set." << endl;
                continue;
            }
            tp = n * (n - 1) / 2;
            res = (tp * 6) / p;
            res = sqrt(res);
            cout << fixed << setprecision(6) << res << endl;
        }
    }
    return 0;
}

ld findCoPrime(vector<ld> vec){
    ld res = 0;
    for(int i = 0; i < vec.size(); i++)
        for(int j = i + 1; j < vec.size(); j++)
            if(isCoPrime(vec[i], vec[j]))
                res++;
    return res;
}

bool isCoPrime(int a, int b){
    int s =  a < b ? a : b;
    int temp = 0;
    for(int i = s; i > 1; i--)
        if(a % i == 0 && b % i == 0)
            return false;
    return true;
}
