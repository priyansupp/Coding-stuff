#include<bits\stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        char mat[n][n];
        for(int j=0;j<n;j++) char[j][j]='X';
//        for(int i=s.length();i>=0;i--){
//            s[i+1]=s[i];
//        }
//        s[0]='0';
        for(int i=0;i<s.length;i++){
            if(s[i]=='1'){
                    for(int j=0;j<s.length();j++){
                            char [i][j]='=';
                    }
            }
            else {
                for(int j=0;j<s.length;j++){
                    if(s[j]=='1') char[i][j]='-';
                }
            }
        }
    }
    return 0;
}

