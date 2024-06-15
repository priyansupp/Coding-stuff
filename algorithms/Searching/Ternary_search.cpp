#include<bits/stdc++.h>
using namespace std;

int X = 90;


//RECURSIVE APPROACH
// int ternary(vector<int>&v, int l, int r){    
//     if(r >= l){
//         int mid1 = l + (r - l)/3;
//         int mid2 = r - (r - l)/3;
//         if(v[mid1] == X){
//             return mid1;
//         }
//         if(v[mid2] == X) {
//             return mid2;
//         }
//         if(X < v[mid1]){
//             return ternary(v, l, mid1 - 1);
//         }
//         if(X > v[mid2]){
//             return ternary(v, mid2 + 1, r);
//         }
//         if(X > v[mid1] && X < v[mid2]){
//             return ternary(v, mid1 + 1, mid2 - 1);
//         }
//     }
//     return -1;
// }



//ITERATIVE APPROACH
// int ternaryiter(vector<int>&v, int l, int r){   
//     while(r >= l){
//         int mid1 = l + (r - l)/3;
//         int mid2 = r - (r - l)/3;
//         if(v[mid1] == X){
//             return mid1;
//         }
//         if(v[mid2] == X){
//             return mid2;
//         }
//         if(X < v[mid1]){
//             r = mid1 - 1;
//         }
//         else if(X > v[mid2]){
//             l = mid2 + 1;
//         }
//         else{
//             l = mid1 + 1;
//             r = mid2 - 1;
//         }
//     }
//     return -1;
// }


int main(){
    vector<int>a={2,3,5,7,8,9,12,46,79,90,123,345,772,891,1999};
    // cout<<ternary(a, 0, 14);
    // cout<<ternaryiter(a, 0, 14);
    
}