#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll size = 10;
ll hash_fn(ll k, char c)
{
   if(c=='a') return k>=0?k%10:(k%10) + 10;
   else return k>=0?k%1000000:(k%1000000) + 1000000; 
}
ll *hash_table;

ll insert_table(ll n, char c)
{
    if(c=='a'){
    ll w = hash_fn(n,c);

    if(hash_table[w]==LLONG_MAX)
    {hash_table[w] = n;return w;}
    else{
        for(ll i = 0; i<10;i++)
        {
            w++;
            if(w==10) {w = 0;}
            if(hash_table[w]==LLONG_MAX)
            {
                //cout<<w<<"$3";
                hash_table[w] = n;
                return w;
            }
        }
    }
}
    else{
ll w = hash_fn(n,c);
    if(hash_table[w]==LLONG_MAX)
    {hash_table[w] = n;return w;}
    else{
        for(ll i = 0; i<1000000;i++)
        {
            w++;
            if(w==1000000) {w = 0;}
            if(hash_table[w]==LLONG_MAX)
            {
                hash_table[w] = n;
                return w;
            }
        }
    }
    }
}

int main()
{
    char c;
cout<<"Enter a or b";
cin>>c;
if(c=='a'){
    hash_table = new ll [10];
    for(ll i = 0; i<10 ; i++)
    {
        hash_table[i] = LLONG_MAX;
    }
    ifstream indata;
    ll num;
    indata.open("test.txt");
    while(!indata.eof())
    {
        indata>>num;
        
       ll k = insert_table(num,c);
     ll ans = 0;
    for(ll k = 3; k<= 10; k++)
    {
ll t = k;
ll f = 0;
for(ll i = 0; i<10; i++)

    ll y = t - hash_table[i];

  ll p =  hash_fn(y,c);
    for(ll j = 0 ; j<9; j++)
    {
        if(hash_table[p]==y && i!=p)
        {
            ans++;
             f = 1;
            break;

        }
        if(f) break;
        p++;
        if(p==10) p = 0;
    }
if(f) break;
}
    }

     cout<<ans<<endl;}
     else

       hash_table = new ll [1000000];
      for(ll i = 0; i<1000000 ; i++)
    {
        hash_table[i] = LLONG_MAX;
    }

    ifstream indata;
    ll num;
    indata.open("challenge.txt");

    for(int i = 0; i<1000;i++)
    {
        indata>>num;
        
       ll k = insert_table(num, c);
       
     
     ll ans = 0;
    for(ll k = -10000; k<= 10000; k++)
    {
ll t = k;
cout<<"running for t "<<t<<endl;
ll f = 0;
for(ll i = 0; i<10000; i++)
{
    ll y = t - hash_table[i];
  ll p =  hash_fn(y,c);
    for(ll j = 0 ; j<9999; j++)
    {
        if(hash_table[p]==y && i!=p)
        {
            ans++;

             f = 1;
            break;

        }
        if(f) break;
        p++;
        if(p==10000) p = 0;
    }
if(f) break;
}
    }
     cout<<ans<<endl;
     }
         
    return 0;
}