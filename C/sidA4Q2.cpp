#include<bits\stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int k;
    k=stoi(argv[1]);
    stack<string>lines;
    ifstream file;
    file.open("input.txt");
    string line;
    while(getline(file,line)){
        lines.push(line);
    }
    for(int i=0;i<k;i++){
        cout<<lines.top()<<endl;
        lines.pop();
    }
    file.close();
    return 0;
}

