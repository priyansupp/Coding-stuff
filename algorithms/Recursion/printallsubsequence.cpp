#include<bits/stdc++.h>
using namespace std;

void printsub(int ind, vector<int> &DS, int arr[], int n){
    if(ind >= n){
        if(DS.empty()){
            cout << "{}" << endl;
            return;
        }
        for(int i : DS){
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    // Taking the index ind into subsequence
    DS.push_back(arr[ind]);
    printsub(ind + 1, DS, arr, n);
    DS.pop_back();

    // NotTaking the index ind into subsequence
    printsub(ind + 1, DS, arr, n);
}



int main()
{
    int n = 3;
    int arr[3] = {3, 1, 2};
    vector<int>DS;  // to store subsequences

    printsub(0, DS, arr, n);

    return 0;
}