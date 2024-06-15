#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; 
    cin >> n >>m;
    vector<int>a(n), b(m), c(m+n);
    for(int i = 0; i < n; i++) cin>> a[i];
    for(int i = 0; i < m; i++) cin>> b[i];
    int i = 0, j = 0, k = 0;  // i pointer points to a vector and j pointer points to b vector

    while(i < a.size() || j < b.size()){
        if(j == b.size() || (i < a.size() && a[i] < b[j])){    // if either j comes to an end and i is not at end then move the i pointer only until the end(if i reaches the end and j is not at end then move the j pointer only..i.e else statement)... or if i is not reached at end and a[i] < b[j] then it is the usual two pointer method movement
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }

    for(int x : c) cout<< x <<" ";
}