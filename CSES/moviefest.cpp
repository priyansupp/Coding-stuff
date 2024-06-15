#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}


int main()
{
    int n; 
    cin >> n;
    vector<pair<int, int>>m(n);
    for(int i = 0; i < n; i++){
        cin >> m[i].first >> m[i].second;
    }
    sort(m.begin(), m.end(), comp);    // sorting by second
    int count = 1, j = 0;              // watching the first film which ends the earliest(m[0].second is the least for it)
    // The idea is to always select the next possible event(that which begins after ending of the current event) which ends as early as possible.
    for(int i = 1; i < n; i++){
        if(m[i].first >= m[j].second){
            count++;
            j = i;
        }
    }
    cout  << count << '\n';
    return 0;

}