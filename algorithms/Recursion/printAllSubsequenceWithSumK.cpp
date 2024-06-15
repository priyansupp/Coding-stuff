#include<bits/stdc++.h>
using namespace std;


// GOING FROM 0 TO N - 1
// void printsub(int ind, int K, int sum, vector<int> &DS, int arr[], int n){
//     if(ind >= n){
//         if(sum == K){
//             for(int i : DS){
//                 cout << i << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     // Taking the index ind into subsequence
//     DS.push_back(arr[ind]);
//     printsub(ind + 1, K, sum + arr[ind], DS, arr, n);   // same as doing sum += arr[i] and then removing arr[i] from sum in next step.
//     DS.pop_back();

//     // NotTaking the index ind into subsequence
//     printsub(ind + 1, K, sum, DS, arr, n);
// }


// GOING FROM N - 1 TO 0
void printsub(int ind, int K, int sum, vector<int> &DS, int arr[], int n){
    if(ind < 0){
        if(sum == K){
            for(int i : DS){
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    // Taking the index ind into subsequence
    DS.push_back(arr[ind]);
    printsub(ind - 1, K, sum + arr[ind], DS, arr, n);
    DS.pop_back();

    // NotTaking the index ind into subsequence
    printsub(ind - 1, K, sum, DS, arr, n);
}



int main()
{
    int n = 3;
    int arr[3] = {1, 2, 1};
    int K = 2;
    vector<int>DS;  // to store subsequences

    // printsub(0, K, 0, DS, arr, n);
    
    printsub(n - 1, K, 0, DS, arr, n);
    return 0;
}