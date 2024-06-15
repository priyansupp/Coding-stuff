#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    if(c=='o' || c=='a' || c=='e' || c=='i' || c=='u' || c=='y'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string ans;
    for(int i=0; i<s.length(); i++){
        if(!isVowel(s[i])){
            ans += '.';
            ans += s[i];
        }
    }
    cout<<ans<<endl;
}
