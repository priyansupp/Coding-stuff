#include<bits/stdc++.h>
using namespace std;

// s = {s[0], s[1], s[2], ..., s[n - 2], s[n - 1]};
// we only have to check till the middle, i.e till n / 2 - 1 (indexing from 0). Therefore, for i >= n / 2, the result would always be true (it'll reach n / 2 only if all the previous comparisons didn't result in false).


bool f(string &s, int i, int n){
    if(i >= n - i - 1){
        return true;
    }

    if(s[i] != s[n - i - 1]){
        return false;
    }
    return f(s, i + 1, n);
}

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    cout << f(s, 0, l);
    return 0;
}