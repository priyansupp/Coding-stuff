#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        vector<int>p;
        for(int i=0;i<n;i++){
            cin>>x;
            p.push_back(x);
        }
        auto it=min_element(p.begin(),p.end());
        deque<int>dq;
        auto t=p.begin();
            dq.push_front(*(t));
        while(t!=it){ 
            t++;       
            if(*(t)>dq.front()) dq.push_back(*(t));
            else dq.push_front(*(t));
        }
        while(it!=p.end()){
            it++;
            dq.push_back(*(it));
        }
        for(int i=0;i<n;i++){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}
