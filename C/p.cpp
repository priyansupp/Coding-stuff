#include<iostream>
#include <utility>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<iterator>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <fstream>
#include<unordered_set>
#include<iterator>

#define ll long long

using namespace std;

vector<string> Path(string start, string end, map<string, string>*prev){
    vector<string>path;
    for(string s=end; s!=""; s = (*prev)[s]){
        path.push_back(s);
    }
    reverse(path.begin(), path.end());
    return path;
}


int main(){
    ifstream input{"sample.txt"};
    map<string, vector<string> >movieActor;
    char delim = '|';
    while(input){
        string actor; 
        getline(input, actor, delim);
        string movie;
        getline(input, movie);
        movieActor[movie].push_back(actor);
        // cout<<actor<<':'<<movie<<'\n';
    }
    //adjacency list
    map<string, unordered_set<string> >actors;
    for(auto i: movieActor){
        queue<string> names;
        ll size = i.second.size();
        for(ll j=0;j < size;j++){
            names.push(i.second.at(j));
        }
        ll times = size;
        ll number = size-1;
        while(times--){
            string now = names.front();
            names.pop();
            names.push(now);
            for(ll a=0;a<number;a++){
                string ite = names.front();
                names.pop();
                names.push(ite);
                if(actors[now].find(ite)==actors[now].end()){
                    actors[now].insert(ite);
                }
            }
            names.pop();
            names.push(now);
        }
    }
    // for(auto i:actors){
    //     cout<<i.first<<": ";
    //     unordered_set<string>::iterator itr;
    //     for(itr = i.second.begin();itr!=i.second.end();itr++){
    //         cout<<(*itr)<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    string start = "Kevin Bacon (I)";
    //bfs
    map<string, string>prev;
    map<string, bool>visited;
    for(auto i:(actors)){
        prev[i.first]="";
        visited[i.first]=false;
    }
    queue<string>n;
    n.push(start);
    visited[start]=true;
    while(!n.empty()){
        string node = n.front();
        n.pop();
        auto neighbours = actors[node];
        for(auto i: neighbours){
            if(!visited[i]){
                n.push(i);
                visited[i]=true;
                prev[i]=node;
            }
        }
    }
    // for(ll i=0;i<ans.size();i++){
    //     cout<<ans[i]<<'\n';
    // }
    for(auto i:actors){
        string end = i.first;
        if(end==start){
            continue;
        }
        auto ans = Path(start, end, &prev);
        if(ans[0]==start){
            cout<<end<<" : "<<ans.size()-1<<"\n";
        }
    }
}