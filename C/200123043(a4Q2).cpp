//PRIYANSHU KUMAR JAISWAL
//200123043
//QUESTION 2
//LAB 4
//Write a program Tail that takes two command line arguments k and input.txt and prints the last k lines of the file input.txt. Use appropriate
//data structure.


#include<bits\stdc++.h>
using namespace std;

void Tail(string filename, int k){
    string line;
    ifstream file;
    stack<string>lines;
    file.open(filename);
    while(getline(file,line)){
        lines.push(line);
    }
    for(int i=0;i<k;i++){
        cout<<lines.top()<<endl;
        lines.pop();
    }
    file.close();

}

int main(int argc, char *argv[])
{
    int k;
    k=stoi(argv[1]);
    string filename="input.txt";
    Tail(filename,k);
    return 0;
}
