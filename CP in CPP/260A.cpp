
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n,temp,c=0;
    string str;
    cin>>a>>b>>n;
    for(int i=0;i<10;i++){
            temp=a;
        str=to_string(a);
        str+=to_string(i);
        a=stoi(str);
        if(a%b==0){
            c=1;
            break;
        }
        else a=temp;
    }
    if(c==0) cout<<-1;
    if(c==1){
            str=to_string(a);
            for(int i=1;i<=n-1;i++){
                str+='0';
            }
        cout<<str;
    }
    return 0;

}
