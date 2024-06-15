#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n,p,q,c=0,t;
    cin>>n>>p;
    set<int>st;
    while(p--) {
            cin>>t;
        st.insert(t);
    }
    cin>>q;
    while(q--){
            cin>>t;
        st.insert(t);
    }
    for(int i=1;i<=n;i++){
        if(st.find(i)==st.end()){
            cout<<"Oh, my keyboard!"<<endl;
            c++;
            break;
        }
    }
    if(c==0) cout<<"I become the guy."<<endl;
}
