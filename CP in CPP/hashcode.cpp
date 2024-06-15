#include<bits/stdc++.h>
using namespace std;

struct skillinfo{
    vector<pair<string, int>>v;
};

class Projectdescription{
    public:
    string proj_name;
    int duration;
    int bestScore;
    int bestBefore;
    int no_of_roles;
    vector<pair<string, int>>skillrequired;
};


// Bob 2
// HTML 5
// CSS 5
// anna 3


int main()
{
    freopen("b_in.txt", "r", stdin);
    freopen("b_out.txt", "w", stdout);
    int contributors, projects;
    cin >> contributors >> projects;
    

    map<string, int>mp;       // {contributors and number of skills}
    vector<skillinfo>skillofcontributors(contributors);
    string name; int no_of_skills;

    int i;
    for(i = 0; i < contributors; i++){
        cin >> name >> no_of_skills;
        mp[name] = no_of_skills;
        // skillofcontributors[i].x = no_of_skills;
        string skillname;
        int skilllevel;
        for(int j = 0; j < no_of_skills; j++){
            cin >> skillname >> skilllevel;
            skillofcontributors[i].v.push_back({skillname, skilllevel});
        }

    }

    string proj_name;
    int duration, bestScore, bestBefore, no_of_roles;
    vector<Projectdescription>listofprojects(projects);
    for(int j = 0; j < projects; j++){
        cin >> proj_name >> duration >> bestScore >> bestBefore >> no_of_roles;
        listofprojects[j].proj_name = proj_name;
        listofprojects[j].duration = duration;
        listofprojects[j].bestScore = bestScore;
        listofprojects[j].bestBefore = bestBefore;
        listofprojects[j].no_of_roles = no_of_roles;
        string skillrequired;
        int levelrequired;
        for(int k = 0; k < no_of_roles; k++){
            cin >> skillrequired >> levelrequired;
            listofprojects[i].skillrequired.push_back({skillrequired, levelrequired});
        }
    }

    for(int i = 0; i < projects; i++){
        int size = listofprojects[i].skillrequired.size();
        for(int j = 0; j < size; j++){
            string skill = listofprojects[i].skillrequired[j].first;
            int level = listofprojects[i].skillrequired[j].second;
            for(int l = level; ; l++){
                
            }
        }
    }



    return 0;
}