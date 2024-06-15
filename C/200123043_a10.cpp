// Priyanshu kumar jaiswal(MnC)
// 200123043
// Lab 10


#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<string> Walk(string startnode, string endnode, map<string, string>*prev){
    vector<string>walk;
    for(string s=endnode; s!=""; s = (*prev)[s]){
        walk.push_back(s);
    }
    reverse(walk.begin(), walk.end());
    return walk;
}

void print(map<string , unordered_set<string> >&m, map<string,string>&prev){
    string startnode="Kevin Bacon (I)";
    for(auto i:m){
        string endnode = i.first;
        if(endnode==startnode) continue;

        auto res = Walk(startnode, endnode, &prev);

        if(res[0]==startnode){
            cout<<endnode<<" : "<<res.size()-1<<"\n";
        }
    }

}

map<string,string> solve(map<string, bool>&visit, map<string , unordered_set<string> >&m, map<string,string>&prev){
    string s="Kevin Bacon (I)";
    queue<string>check;
    check.push(s);
    visit[s]=true;
    while(!check.empty()){
        string node = check.front();
        check.pop();
        auto neighbours = m[node];
        for(auto i: neighbours){
            if(!visit[i]){
                check.push(i);
                visit[i]=true;
                prev[i]=node;
            }
        }
    }
    return prev;
}

int main()
{
    string line;
    ifstream File1;
    File1.open("imdb.top250.txt");
        long long n=0;
        while(getline(File1, line))
            n++;
    File1.close();
    ifstream  input{"imdb.top250.txt"};
    
    map<string, vector<string> > mp;
        char del='|';
        while(input){
        string actor; 
        string movie;
        getline(input, actor, del);
        getline(input, movie);
        mp[movie].push_back(actor);
    }



    map<string , unordered_set<string> >m;
    for(auto movie: mp){
        queue<string>actorname;
        for(long long i=0;i<movie.second.size();i++){
            actorname.push(movie.second[i]);
        }

        long long size=movie.second.size();
        for(long long t=0;t<size;t++){
            string s=actorname.front();
            actorname.pop();
            actorname.push(s);
            for(long long k=0;k<size-1;k++){
                string temp=actorname.front();
                actorname.pop();
                actorname.push(temp);
                m[s].insert(temp);

            }
            actorname.pop();
            actorname.push(s);
        }
    }

    map<string, string>prev;
    map<string, bool>visit;
    for(auto i:(m)){
        prev[i.first]="";
        visit[i.first]=false;
    }

    prev = solve(visit,m,prev);
    print(m,prev);


    return 0;
}




