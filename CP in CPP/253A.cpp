#include <bits/stdc++.h>

using namespace std;
using std::string;

#define ll long long
#define ull unsigned long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define forr1(i,n) for(ll i=1;i<n;i++)
#define pb push_back
#define ft              first
#define sd              second
#define sd              second
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define revsrt(v)       sort(v.begin(),v.end(),greater<ll>())
#define minV(v)         *min_element(v.begin(),v.end())
#define maxV(v)         *max_element(v.begin(),v.end())
#define fill(v,s)       iota(v.begin(),v.end(),s)     //fills vector v with sequence of numbers starting from s, s+1,s+2.....
#define sum(v, initial) accumulate(v.begin(),v.end(),initial)  //initial is the starting sum and then the vector values are added to it.
#define all(v)          v.begin(),v.end()
#define mod             1000000007





int main()
{
    ifstream file;
    file.open("input.txt");
    string line;
    getline(file,line);
    stringstream ss;
    ss<<line;
    string temp;
    int found;
    int n,m,i=1;
    while(!ss.eof()){
        ss>>temp;
        if (stringstream(temp) >> found){
            if(i==1) n=found;
            else m=found;
        }
        i++;
    }
    file.close();

    ofstream outputfile("output.txt");
    string s="";
    if(n>=m){
        while(m--){
            s+="BG";
            n--;
        }
        while(n--) s+='B';
        outputfile<<s;
    }
    else{
        while(n--){
            s+="GB";
            m--;
        }
        while(m--) s+='G';
        outputfile<<s;
    }
    outputfile.close();
    return 0;
}
