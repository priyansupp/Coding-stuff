#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back


int main()
{
    int n;
    ll k;
    cin>>n>>k;
    queue<int>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    if(k>=n-1){
    cout<<n<<endl;
    }
    else{
    int ans=a[0];
    int win=0;
        for(int i=1;i<n;i++){
            q.push(a[i]);
        }
        while(win<k){
            int x=q.front();
            if(ans>x){
                q.pop();
                q.push(x);
                win++;
            }
            else{
                q.pop();
                q.push(ans);
                ans=x;
                win=1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}