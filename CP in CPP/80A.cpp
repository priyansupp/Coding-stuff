#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,i,c=0;
    cin>>x>>y;
    for(i=x+1;;i++){
            c=0;
        for(int j=i-1;j>1;j--){
            if(i%j==0){
                c=1;
                break;
            }
        }
        if(c==0){
                if(i==y) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            break;
        }
    }
    return 0;
}


