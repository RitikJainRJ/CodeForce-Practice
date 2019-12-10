/*
There are n cities in Bearland, numbered 1 through n. Cities are arranged in one long row. The distance
between cities i and j is equal to |i - j|.
Limak is a police officer. He lives in a city a. His job is to catch criminals. It's hard because he doesn't
know in which cities criminals are. Though, he knows that there is at most one criminal in each city.
Limak is going to use a BCD (Bear Criminal Detector). The BCD will tell Limak how many criminals there are
for every distance from a city a. After that, Limak can catch a criminal in each city for which he is sure
that there must be a criminal.
You know in which cities criminals are. Count the number of criminals Limak will catch, after he uses the BCD.
*/
#include<bits/stdc++.h>
using namespace std;

int numCriminal(int[], int, int);

int main(void){
    int n, a;

    cin >> n >> a;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << numCriminal(arr, n, a - 1) << endl;
    return 0;
}

int numCriminal(int arr[], int n, int a){
    int temp = 0;
    if(arr[a] == 1)
        temp++;
    for(int i = 1; i < n; i++){
        if(a - i >= 0 && a + i < n){
            if(arr[a - i] == 1 && arr[a + i] == 1)
                temp += 2;
        }
        else{
            if(a - i >= 0 && arr[a - i] == 1)
                temp++;
            if(a + i < n && arr[a + i] == 1)
                temp++;
        }
    }
    return temp;
}
