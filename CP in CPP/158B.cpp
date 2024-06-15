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
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()



int main()
{
    int n;
    cin>>n;
    vector<int>s(n);
    forr(i,n) cin>>s[i];
    sort(s);
    rev(s);
    int car1=0,car2=0,car3=0,car4=0;
    forr(i,n){
        if(s[i]==4){
            car4++;
        }
        else if(s[i]==3){
            car3++;
        }
        else if(s[i]==2){
            car2++;
        }
        else car1++;
    }
    car1-=car3;
    if(car2%2!=0){
        car1-=2;
        car2/=2;
        car2++;
    }
    else car2/=2;

    if(car1%4==0 && car1>0) car1/=4;
    else if(car1%4!=0 && car1>0){
        car1/=4;
        car1++;
    }

    if(car1>0) cout<<car1+car2+car3+car4;
    else cout<<car2+car3+car4;
    return 0;
}
