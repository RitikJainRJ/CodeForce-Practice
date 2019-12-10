/*
Little Petya often travels to his grandmother in the countryside. The grandmother has a large garden,
which can be represented as a rectangle 1 × n in size, when viewed from above. This rectangle is divided
into n equal square sections. The garden is very unusual as each of the square sections possesses its own
fixed height and due to the newest irrigation system we can create artificial rain above each section.
Creating artificial rain is an expensive operation. That's why we limit ourselves to creating the artificial
rain only above one section. At that, the water from each watered section will flow into its neighbouring
sections if their height does not exceed the height of the section. That is, for example, the garden can
be represented by a 1 × 5 rectangle, where the section heights are equal to 4, 2, 3, 3, 2. Then if we create
an artificial rain over any of the sections with the height of 3, the water will flow over all the sections,
except the ones with the height of 4. See the illustration of this example at the picture:
*/

#include<bits/stdc++.h>
using namespace std;

int maxWaterSection(int[], int);
int _mws(int[], int, int);

int main(void){
    int n;

    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxWaterSection(arr, n) << endl;
    return 0;
}

int maxWaterSection(int arr[], int n){
    int max = 0, temp;
    for(int i = 0; i < n; i++){
        temp = _mws(arr, n, i);
        if(max < temp)
            max = temp;
    }
    return max;
}

int _mws(int arr[], int n, int index){
    int count = 1;
    for(int i = index + 1; i < n; i++)
        if(arr[i] <= arr[i - 1])
            count++;
        else
            break;
    for(int i = index - 1; i >= 0; i--)
        if(arr[i] <= arr[i + 1])
            count++;
        else
            break;
    return count;
}
