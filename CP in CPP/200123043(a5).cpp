//PRIYANSHU KUMAR JAISWAL
//200123043
//QUESTION 1
//LAB 5
//Write a program Tail that takes two command line arguments k and input.txt and prints the last k lines of the file input.txt. Use appropriate
//data structure.


#include<bits\stdc++.h>
using namespace std;
class numb{
    public:
        int a;
        int b;
        int c;
        numb(int a, int b, int c): a(a),b(b),c(c)
        {
        }
};

bool operator<(const numb& n1, const numb& n2)
{
    return n1.a>n2.a;
}

int main()
{
    int n;
    cin>>n;
    priority_queue<numb>pq;
    for(int i=0;i<=n;i++){
//            vector<int> data{};
        pq.push(numb(i*i*i,i,0));
    }
    numb non=pq.top();
    cout<<non.a<<" "<<non.b<<" "<<non.c<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                numb non=pq.top();
                pq.pop();
                pq.push(numb(i*i*i+(j+1)*(j+1)*(j+1),i,j+1));
                cout<<non.a<<" "<<non.b<<" "<<non.c<<endl;
        }
    }
    return 0;
}
