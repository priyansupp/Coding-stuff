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
#include <stdio.h>

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
#define srt(v)         sort(v.begin(),v.end())
#define revsrt(v)      sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()

int n,i,a[100500],rez,l;

int main()
{
    scanf("%d%d",&n,&l);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n); 
    //Also we need to consider street bounds and count distances from outside lanterns to street bounds, it will be (a[0] - 0) and (l - a[n - 1]). The answer will be max(maxdist / 2, max(a[0] - 0, l - a[n - 1]))
    rez = 2*max(a[0],l-a[n-1]);
    for (i = 0; i < n-1; i++)
        rez = max(rez, a[i+1]-a[i]);
    printf("%.10f\n",rez/2.);
    return 0;
}
