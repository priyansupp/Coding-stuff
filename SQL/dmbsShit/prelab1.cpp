#include<bits/stdc++.h>
using namespace std;
set<int> keys;
int pp(int x)
{
    if(x==0)return 0;
    x--;
    int ans=1;
    while(x--)ans*=2;
    return ans; 
}
int bpc(int x)
{
    int ans=0;
    while(x){ans+=x%2;x/=2;}
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > rel;
    vector<int> ans;
    cin.ignore();




    
    while(m--)
    {
    string t;
    getline(cin,t);
    pair<int,int> x={0,0};
    int ca=0;
    for(int id=0;id<t.size();id++)
    {
        char c=t[id];
        if(c==' ')
        {
            x.first+=pp(ca);
            ca=0;
        }
        else
        {
            ca*=10;
            ca+=(c-'0');
        }
    }
    x.first+=pp(ca);
    string s;
    getline(cin,s);
    
    ca=0;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(c==' ')
        {
            x.second+=pp(ca);
            ca=0;
        }
        else
        {
            ca*=10;
            ca+=(c-'0');
        }
    }
    x.second+=pp(ca);
    cout<<x.first<<' '<<x.second<<'\n';
    rel.push_back(x);
    }





    m=rel.size();
    int ccl=0;
    for(int i=0;i<1<<n;i++)
    {
        ccl=i;
        
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<m;j++)
            {
                if(((ccl)|(rel[j].first))==ccl)ccl|=rel[j].second;
            }
        }
        
        if((ccl+1)==(1<<n))
        {
            ans.push_back(i);
        }
    }
   
    vector<int> fa;
    for(int i=0;i<ans.size();i++)
    {
        bool res=1;
        for(int j=0;j<ans.size();j++)
        {
            if(i!=j && (ans[i]|ans[j])==ans[i])
            {
                res=0;
            }
        }
        if(res)fa.push_back(ans[i]);
    }
    cout<<fa.size()<<'\n';
    vector<vector<int>> v;
    for(int i=0;i<fa.size();i++)
    {
        int x=fa[i];
        vector<int> vv;
        vv.push_back(0);
        int y=1;
        while(x)
        {
            if(x%2)
            {
            vv[0]++;
            vv.push_back(y);
            }
            y++;
            x/=2;
        }
        v.push_back(vv);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        vector<int> vv=v[i];
        for(int i=1;i<vv.size();i++)cout<<vv[i]<<' ';
        cout<<'\n';
    }    
}