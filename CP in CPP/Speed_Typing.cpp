#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    for(int cc = 1; cc <= t; cc++){
        string I, P;
        cin >> I >> P;
        int l1 = I.length();
        int l2 = P.length();
        int i = 0, j = 0;
        int change = 0;
        for(i = 0; i < l1; i++, j++){
            while(I[i] != P[j] && j < l2){
                j++;
                change++;
            }
            if(j == l2){
                break;
            }
        }
        change += l2 - j;
        if(i == l1){
            cout << "Case #" << cc << ": " << change << '\n'; 
        }else{
            cout << "Case #" << cc << ": IMPOSSIBLE\n";
        }
        
    }
    return 0;
}