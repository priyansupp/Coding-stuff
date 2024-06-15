#include<bits/stdc++.h>
using namespace std;

int sizeofpage;

vector<vector<pair<int, int>>>v;        // vector of vector of {sizeofrecord, pk}

void Insert(int size, int pk){
    if(v.empty()){
        vector<pair<int, int>>w = {{size, pk}};
        v.push_back(w);
        return;
    }
    for(int i = 0; i < v.size(); i++){
        int total = 0;                 // total space used
        for(int j = 0; j < v[i].size(); j++){
            total += v[i][j].first;
        }
        if(sizeofpage - 16 - total - 4 * v[i].size() >= size + 4){  // if remaining space is greater than what's required to store the incoming record
            v[i].push_back({size, pk});
            return;
        }
    }
    v.push_back({{size, pk}});        // else make a second page
    return;
}

void Status(){
    cout << v.size() << " ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i].size() << " ";
    }
    cout << '\n';
    return;
}

void Search(int pk){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j].second == pk){
                cout << i << " " << j << '\n';
                return;
            }
        }
    }
    cout << "-1 -1\n";
    return;
}

int main()
{
    cin >> sizeofpage;
    int x;
    cin >> x;
    while(x != 4){
        if(x == 1){
            int size;
            int primary_key;
            cin >> size >> primary_key;
            Insert(size, primary_key);
        }
        else if(x == 2){
            Status();
        }
        else{
            int primary_key;
            cin >> primary_key;
            Search(primary_key);
        }
        cin >> x;
    }
    return 0;
}

