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
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define sort(v)         sort(v.begin(),v.end())
#define revsrt(v)      sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()



int main()
{
    int n;
    cin>>n;
    vector<string>s(n);
    forr(i,n) cin>>s[i];
    vector<string>hash(1e5,"");

    forr(i,n){
        int j;
        int count=0;
        for(j=0;j<=i;j++){
            int c=0;
            if(hash[j]=="" && count==0){
                hash[j]=s[i];
                cout<<"OK"<<endl;
            }
            else if(hash[j]=="" && count!=0){
                string counts=to_string(count);
                hash[j]=s[i]+counts;
                cout<<hash[j]<<endl;
            }
            else{
                int k;
                for(k=0;k<s[i].length();k++){
                    if(hash[j][k]!=s[i][k]){
                        c=1;
                        break;
                    }
                }
                if((c==0 && isdigit(hash[j][k])) || k==hash[j].length()) count++;
            }
        }
    }

    return 0;
}
