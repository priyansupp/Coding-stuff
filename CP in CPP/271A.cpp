
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string n,str;
    cin>>n;
    int year=stoi(n);
    for(int i=year+1;;i++){
        str=to_string(i);
        if(str[0]!=str[1] && str[1]!=str[2] && str[2]!=str[3] && str[3]!=str[0] && str[3]!=str[1] && str[0]!=str[2]){
            cout<<str;
            break;
        }
    }


}
