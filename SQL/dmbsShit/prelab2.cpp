#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>D;
vector<int>local_depth;
int bucket_capacity = 0;

void Insert(int input, int &global_depth){
    bitset<25>A(input);
    for(int i = 0; i < (1 << global_depth); i++){
        int l = local_depth[i];
        bitset<25>L(l);
        int c = 0;
        for(int j = 25 - l - 1; j < 25; j++){
            if(A[j] != L[j]){
                c = 1;
                break;
            }
        }
        if(c == 0){
            if(D[i].size() < bucket_capacity){
                D[i].push_back(input);
            }else{
                global_depth++;
                D.resize(bucket_capacity, vector<int>(1 << global_depth));
                local_depth.resize(1 << global_depth, global_depth);
                local_depth[i]++;
                Insert(input, global_depth);
            }
        }
    }
}

int Search(int input, int global_depth){
    for(int i = 0; i < (1 << global_depth); i++){
        auto it = find(D[i].begin(), D[i].end(), input);
        if(it != D[i].end()){
            return i + 1;
        }
    }
    return INT_MIN;
}

void Delete(int input, int global_depth){
    for(int i = 0; i < (1 << global_depth); i++){
        auto it = find(D[i].begin(), D[i].end(), input);
        if(it != D[i].end()){
            D[i].erase(it);
        }
    }
    return;
}

void Display(int global_depth){
    cout << global_depth << '\n';
    for(int i = 0; i < (1 << global_depth); i++){
        cout << local_depth[i] << " " << D[i].size() << '\n';
    }
}


int main()
{
    int global_depth;
    cin >> global_depth >> bucket_capacity;
    D.resize(bucket_capacity, vector<int>(1 << global_depth));
    local_depth.resize(1 << global_depth, global_depth);
    while(1){
        int x;
        cin >> x;
        if(x == 6){
            break;
        }
        if(x == 2){
            int input;
            cin >> input;
            Insert(input, global_depth);
        }else if(x == 3){
            int input;
            cin >> input;
            int out = Search(input, global_depth);
            if(out != INT_MIN){
                cout << out << '\n';
            }
        }else if(x == 4){
            int input;
            cin >> input;
            Delete(input, global_depth);
        }else{
            Display(global_depth);
        }
    }

    return 0;
}