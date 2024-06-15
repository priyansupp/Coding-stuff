
//PRIYANSHU KUMAR JAISWAL
//200123043
//QUESTION 2
//LAB 5
//Find all solutions to the equation a+ 2b2 = 3c3 + 4d4 for which a, b, c, and d are less than 100,000. Hlong long: use one min heap and one max heap.


#include<bits/stdc++.h>
using namespace std;

class nos{
    public:
    long long n1;
    long long n2;
    long long n3;
    nos(long long n1,long long n2,long long n3):n1(n1),n2(n2),n3(n3){

    }
};

bool operator<(const nos& p1, const nos& p2)
{
    return p1.n1 > p2.n1;
}


int main()
{
    long long n=1000;
    priority_queue<nos>minheap;
    for(long long i=0;i<n;i++){
        minheap.push(nos(i,i,0));
    }
    priority_queue<nos>maxheap;
    for(long long i=0;i<n;i++){
        maxheap.push(nos(3*i*i*i,i,0));
    }
    vector<nos>vect1;

    for(long long i=0;i<(n+1)*(n+1);i++){
        nos res=minheap.top();
        minheap.pop();
        if(res.n3<n){
            maxheap.push(nos(res.n2+2*pow(res.n3+1,2),res.n2,res.n3+1));
        }
        vect1.push_back(res);
    }
    cout<<endl;
    vector<nos>vect2;
    for(long long i=0;i<(n+1)*(n+1);i++){
        nos res=maxheap.top();
        maxheap.pop();
        if(res.n3<n){
            maxheap.push(nos(3*pow(res.n2,3)+4*pow(res.n3+1,4),res.n2,res.n3+1));
        }
        vect2.push_back(res);
    }
    for(long long i=0;i<vect1.size();i++){
        for(long long j=0;j<vect2.size();j++){
            if(vect1[i].n1==vect2[j].n1){
                cout<<vect1[i].n2<<" "<<vect1[i].n3<<" "<<vect2[j].n2<<" "<<vect2[j].n3<<endl;
            }
        }
    }
    return 0;

}
