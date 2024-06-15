#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<bool>mark(n, false);
    int count = 0;
    for(int i = 2;count < n;){
        if(!mark[i]){
            cout << i%n << " ";
            i += 2;
            i %= n;
        }
        else{
            int j = i;
            while(mark[j]){
                j++;
                j %= n;
            }
            cout << j << " ";
            i = j;
        }
        count++;
    }
    return 0;
}