#include<bits/stdc++.h>
using namespace std;

int H[(int)1e7 + 1];

int main()
{
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int>X(N);
    for(int i = 0; i < N; i++) cin >> X[i];
    for(int i = 0; i < N; i++){
        H[X[i]]++;
    }
    vector<int>queries(Q);
    for(int i = 0; i < Q; i++) cin >> queries[i];
    for(int i = 0; i < Q; i++){
        if(H[queries[i]] != 0){
            cout << H[queries[i]] << " ";
        }else{
            int j = queries[i];
            for(int k = 1; ; k++){
                if((j - k > 0 && H[j - k] != 0) || (j + k < 1e7 + 1 && H[j - k] != 0)){
                    cout << H[j - k] << " ";
                }
            }
        }
    }
    return 0;
}