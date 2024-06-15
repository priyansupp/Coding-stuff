#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <vector>
#include <deque>
#include <numeric>
#include <cstdlib>
#include <bitset>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>
#include <iterator>
#include <array>
#include <complex>

using namespace std;
using std::string;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define PB push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         min_element(v.begin(),v.end())   //to get iterator pointing to minimum element
#define maxV(v)         max_element(v.begin(),v.end())   //to get iterator pointing to maximum element



int main()
{
    int n;
    cin>>n;
    vector<int>w(n);
    forr(i,n) cin>>w[i];

    string s;
    cin>>s;

    vector<int>extro;
    vector<int>occbyintroposition;

    int j=0;
    forr(i,2*n){
        if(s[i]=='0'){
            int index1=min_element(w.begin(),w.end())-w.begin();
            cout<<index1+1<<" ";
            occbyintroposition.PB(index1);
            extro.PB(w[index1]);
            w[index1]=INT_MAX;
        }
        else{
                int index2=max_element(extro.begin(), extro.end())-extro.begin();
                extro[index2]=0;
                cout<<occbyintroposition[index2]+1<<" ";
        }
    }
    cout<<'\n';
    return 0;
}
