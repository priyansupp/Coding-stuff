#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // for(int i=0;i<k;i++){    
    //     int x;
    //     cin>>x;          // search for x in the array
    //     int l=0;
    //     int r=n-1;
    //     bool ok = false;
    //     while(r >= l){           //Normal binary search
            // int m = l + (r - l) / 2;
    //         int m=(l + r)/2;    //middle element... [3,5,7,12] has 5 as middle element. [1,2,3,4,5] has 3 as middle element
    //         if(a[m] == x){
    //             ok = true;
    //             break;
    //         } 
    //         else if(a[m] < x){
    //             l = m+1;
    //         }
    //         else if(a[m] > x){
    //             r = m-1;
    //         }
    //     }

    //     if(ok){
    //         cout<<"YES\n";
    //     }
    //     else{
    //         cout<<"NO\n";
    //     }

    // }


    // for(int i=0;i<k;i++){    
    //     int x;
    //     cin>>x;                //maximum index of an array element not greater than x
                               // i.e max i: a[i] <= x
    
    // we assign index -1 to -inf and index n to +inf so as to compensate for edge cases when no element in array is <= x. The r pointer will move to index 0 and l will remain at -1. We can print l+1 to denote the first element is closest to x when every element is greater than x.

    //     int l=-1;   //l:a[l] <= x
    //     int r=n;    //r:a[r] > x
    //     while(r > l+1){   //i.e unless the l,r pointers are not consecutive.
    //         int m = (l + r)/2;
    //         if(a[m] <= x){
    //             l = m;   //coming closest, we can't jump to m+1 as x can be in between a[m] & a[m+1].
    //         }
    //         else{
    //             r = m;  //coming closest, we can't jump to m-1 as x can be in between a[m-1] & a[m].
    //         }
    //     }
    //     cout<<l<<"\n";   //maximum index of an array element not greater than x, i.e max i: a[i] <= x is at i = l.

    // to convert into binary search just check value at index l. It x exists in array a then it'll come in index l(as l contains a[l] <= x). ADVANCED BINARY SEARCH
    // if(l >= 0 && a[l] == x){
    //     cout<<"YES\n";
    // }
    // else{
    //     cout<<"NO\n";
    // }

    // }

    for(int i=0;i<k;i++){    
        int x;
        cin>>x;                // minimum index of an array element not less than x
                               // i.e min i: a[i] >= x
    
        // we assign index -1 to -inf and index n to +inf so as to compensate for edge cases when no element in array is >= x. The l pointer will move to index n-1 and r will remain at n. We can print r to denote the first element is closest to x when every element is greater than x.

        int l=-1;   //l:a[l] < x
        int r=n;    //r:a[r] >= x
        while(r > l+1){   //i.e unless the l,r pointers are not consecutive.
            int m = (l + r)/2;
            if(a[m] < x){
                l = m;   //coming closest, we can't jump to m+1 as x can be in between a[m] & a[m+1].
            }
            else{
                r = m;  //coming closest, we can't jump to m-1 as x can be in between a[m-1] & a[m].
            }
        }
        cout<<r<<"\n";   //max ind for which x is closest to a[r] >= x. Print n+1 if no such index exists.

        // to convert into binary search just check value at index r. It x exists in array a then it'll come in index r(as r contains a[r] >= x). ADVANCED BINARY SEARCH
        // if(r < n && a[r] == x){
        //     cout<<"YES\n";
        // }
        // else{
        //     cout<<"NO\n";
        // }

    }

}