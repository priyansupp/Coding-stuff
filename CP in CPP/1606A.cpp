#include <iostream>
#include <cmath>
#include <utility>
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
#include <deque>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <bitset>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsort(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())



int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l=s.length();
        int ab=0,ba=0;
        forr(i,l-1){
            if(s[i]=='a' && s[i+1]=='b') ab++;
            if(s[i]=='b' && s[i+1]=='a') ba++;
        }
        string str="";
        if(ab==ba) cout<<s;
        else if(ab>ba){
            for(int i=1;i<l;i++) str+=s[i];
        }
        else{
            for(int i=1;i<l;i++) str+=s[i];
        }
        if(ab>ba){
            cout<<"b"<<str;
        }
        else if(ba>ab){
            cout<<"a"<<str;
        }
            cout<<endl;


    }

    return 0;
}
