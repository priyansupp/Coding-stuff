#include<bits/stdc++.h>
using namespace std;


// GOING FROM 0 TO N - 1
bool printsub(int ind, int K, int sum, vector<int> &DS, int arr[], int n){
    if(ind >= n){
        // condition satisfied
        if(sum == K){
            for(int i : DS){
                cout << i << " ";
            }
            cout << endl;
            return true;
        }

        // condtion not satisfied
        return false;
    }

    DS.push_back(arr[ind]);
    sum += arr[ind];
    if(printsub(ind + 1, K, sum, DS, arr, n) == true){
        return true;
    }

    DS.pop_back();
    sum -= arr[ind];

    if(printsub(ind + 1, K, sum, DS, arr, n) == true){
        return true;
    }

    return false;   // if none of the function calls return true.
}

// GOING FROM N - 1 TO 0
// bool printsub(int ind, int K, int sum, vector<int> &DS, int arr[], int n){
//     if(ind < 0){
//         // condition satisfied
//         if(sum == K){
//             for(int i : DS){
//                 cout << i << " ";
//             }
//             cout << endl;
//             return true;
//         }
//         // condition not satisfied
//         return false;
//     }

//     DS.push_back(arr[ind]);
//     sum += arr[ind];
//     if(printsub(ind - 1, K, sum, DS, arr, n) == true){
//         return true;
//     }

//     DS.pop_back();
//     sum -= arr[ind];

//     if(printsub(ind - 1, K, sum, DS, arr, n) == true){
//         return true;
//     }

//     return false;   // if none of the function calls return true.
// }



int main()
{
    int n = 3;
    int arr[3] = {1, 2, 1};
    int K = 2;
    vector<int>DS;  // to store subsequences

    printsub(0, K, 0, DS, arr, n);
    
    // printsub(n - 1, K, 0, DS, arr, n);
    return 0;
}