#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N], seg[4 * N];

// with base 0 indexing of the root node, we take left child as 2*ind + 1 and 2*ind + 2. In base 1 as root, left is 2*ind and right is 2*ind+1.
void buildseg(int ind, int low, int high){
    if(low == high){
        seg[ind] = a[low];  // (= a[high])
        return;
    }
    int mid = (low + high) / 2;
    buildseg(2 * ind + 1, low, mid);
    buildseg(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// a node with range low to high means it contains the segment [low, high], i.e a total of high - low + 1 leaf nodes sum.
int query(int ind, int low, int high, int l, int r){
    if(l <= low && r >= high){
        return seg[ind];
    }
    if(low > r || high < l){
        return INT_MIN;
    }
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    buildseg(0, 0, n - 1);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << '\n';
    }
    return 0;
}