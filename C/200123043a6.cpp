#include<bits/stdc++.h>
using namespace std;

bool pairss(long long arr[], long long size, int target)
{
    unordered_set<int>ust;
    for(int i=0;i<size;i++){
        int temp=target-arr[i];
        if(ust.find(temp)!=ust.end()) return true;
        ust.insert(arr[i]);

    }
}

int main()
{
    string line;
    ifstream File1, File2;
    File1.open("test.txt");
        long long n=0;
        while(getline(File1, line))
            n++;
    File1.close();
        long long arr[n];
    File2.open("test.txt");
        long long i=0;
        while(getline(File2, line)){
            arr[i] = (long long)stoi(line);
            i++;
        }
    int t[8];
    int a=3,countt=0;
    for(int i=0;i<8;i++) {
        t[i]=a;
        a++;
    }
    for(int i=0;i<8;i++){
        if(pairss(arr,n,t[i])) countt++;
    }
    cout<<countt<<endl;
    return 0;
}