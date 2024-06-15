#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; 
    cin >> n >>m;
    vector<int>a(n), b(m);
    for(int i = 0; i < n; i++) cin>> a[i];
    for(int i = 0; i < m; i++) cin>> b[i];
    int i = 0, j = 0;  // i pointer points to a vector and j pointer points to b vector

    // the number of elements smaller than every b[j] in a is the number of a's elements that'll come in front of the b[j] element in final sorted array formed by merging. But we don't need to form the final sorted vector, we can just look at the number of times i pointer has moved for every j pointer(those many elements would be placed in the final sorted array, which we didn't construct).
    vector<int>res(m);
    while(i < n || j < m){
        if(j == m || (i < n && a[i] < b[j])){
            i++;     // moving the pointer in a vector
        }
        else{
            res[j] = i;   // i element from a would be before b[j]
            j++;
        }
    }


    // CAN ALSO USE THIS
    // for(j = 0 ; j < m; j ++){
    //     while(i < n && a[i] < b[j]){
    //         i++;
    //     }
    //     res[j] = i;
    // }

    for(int x : res) cout << x <<" ";

}