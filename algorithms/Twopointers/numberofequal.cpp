#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; 
    cin >> n >>m;
    vector<long long>a(n), b(m);
    for(int i = 0; i < n; i++) cin>> a[i];
    for(int i = 0; i < m; i++) cin>> b[i];


    // SOLUTION USING MAP  O(nlogn)
    // map<long long, long long>ma,mb;
    // for(int i = 0; i < n; i++) ma[a[i]]++;
    // for(int j = 0; j < m; j++) mb[b[j]]++;


    // long long res = 0;
    // for(map<long long, long long>::iterator itr = ma.begin(); itr != ma.end(); itr++){
    //     map<long long, long long>::iterator it = mb.find(itr->first);
    //     if(it != mb.end()) {
    //         res += (itr->second)*(it->second);
    //     }
    // }
    // cout << res <<'\n';


    // TWO POINTER METHOD    O(n)

    long long res = 0;

    int  i = 0, j = 0;
    while(i < n && j < m){   // if any one of them turns to the end then there wont be any element left to compare the equality with in that vector
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else{       // a[i] = b[j]
            long long k1 = i, k2 = j;          //can't take int as it'll cause integer overflow below when multiplying.
            while(k1 < n && a[k1] == a[i]){
                k1++;
            }
            while(k2 < m && b[k2] == b[j]){
                k2++;
            }
            res += (k1 - i)*(k2 - j);      
            j = k2;
            i = k1;
        } 
    }
    cout << res << '\n';


    return 0;
}