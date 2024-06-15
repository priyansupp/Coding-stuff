#include<bits/stdc++.h>
using namespace std;

void shiftright(int arr[], int l, int r, int d)        //shifting portion of array right by d unit offset.
{
    //arr[l] to arr[r] rotated by d units to the left
    int length=r-l+1;
    int copy[length];
    int j=0;
    for(int i=l;i<=r;i++){
        copy[j]=arr[i];        //when i is l, j is 0 when i is x+l, j would be i-l=x;
        j++;
    }
    for(int i=l;i<=r;i++){
        arr[((i+d-l)%length)+l]=copy[i-l];    //very important, think it through.
                                              //for arr(2,6,3), arr[2] takes in value arr[4] i.e copy[4-2]
    }

}
void shiftleftbyone(int arr[],int l,int r){
    int x=arr[l];
    for(int i=l;i<r;i++){
        arr[i]=arr[i+1];
    }
    arr[r]=x;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<pair<int,int>>res;
        for(int i=n-1;i>0;i--){
            int max_ind=i;
            for(int j=i-1;j>=0;j--){
                if(arr[j]>arr[max_ind]) max_ind=j;
            }
            if(max_ind!=i){
                shiftleftbyone(arr,max_ind,i);
                res.push_back({max_ind+1,i+1});
                k++;
            }
        }
        cout<<k<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i].first<<" "<<res[i].second<<" "<<1<<endl;
        }
    }
    return 0;
}