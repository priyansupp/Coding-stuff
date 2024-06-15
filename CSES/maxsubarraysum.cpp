#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    long long sum = 0, maxisum = INT_MIN;
    for(int r = 0; r < n; r++){
        sum += x[r];
        maxisum = max(maxisum, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    cout << maxisum;

    return 0;
}