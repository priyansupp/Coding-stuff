//PRIYANSHU KUMAR JAISWAL
//200123043
//QUESTION 1
//LAB 5


#include<bits\stdc++.h>
using namespace std;
class numb{
    public:
        long long a;
        long long b;
        long long c;
        numb(long long a, long long b, long long c): a(a),b(b),c(c)
        {
        }
};

bool operator<(const numb& n1, const numb& n2)
{
    return n1.a>n2.a;
}

int main()
{
    long long n;
    cin>>n;
    priority_queue<numb>pq;
    for(long long i=0;i<=n;i++)  pq.push(numb(i*i*i,i,0));

    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
                numb non=pq.top();
                pq.pop();
                pq.push(numb(i*i*i+(j+1)*(j+1)*(j+1),i,j+1));
                cout<<non.a<<" "<<non.b<<" "<<non.c<<endl;
        }
    }
    return 0;
}
