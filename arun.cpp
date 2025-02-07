#include<bits/stdc++.h>
using namespace std;

    // A[l..mid].f is sorted and A[mid+1..r].f is sorted
    // NOTE : We cannot start merging from the start(i.e i=l and j=mid+1), because if A[i].first > A[j].first it means for all A[i].first > A[x].first for all mid+1 <= x <= j, hence we add ans[A[i].second] += (j-mid) and place A[j] into B[k]. But as A[i+1].first > A[j].first, but we are not adding (j-mid) into ans[A[i+1].second]. To solve this problem we merge from the end and greedily bigger values in B. 
    // start merging from the end and then merge
        // If A[i].first > A[j].first it means for all A[i].first > A[x].first for all mid+1 <= x <= j, hence we add ans[A[i].second] += (j-mid) and place A[i] into B[k]
typedef long long ll;

void merge(vector<pair<int, int>>&A, vector<int>& ans, int l, int mid, int r) {
    vector<pair<int, int>>B(r - l + 1);
    int k = r - l, i = mid, j = r;
    while(i >= l || j >= mid + 1) {
        if(j == mid || (i >= l && A[i].first > A[j].first)) {
            ans[A[i].second] += (j - mid);
            B[k] = A[i];
            i--;
        } else {
            B[k] = A[j];
            j--;
        }
        k--;
    }
    for(int i = l; i <= r; i++) A[i] = B[i - l];
}

void mergesort(vector<pair<int, int>>& A, vector<int>& ans, int i, int j) {
    if(i == j) return;
    int mid = (i + j) / 2;
    mergesort(A, ans, i, mid);
    mergesort(A, ans, mid + 1, j);
    merge(A, ans, i, mid, j);
}

vector<int> constructLowerArray(vector<int> &arr, int n)
{

    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
        v.push_back({ arr[i], i });
    vector<int> ans(n, 0);
    mergesort(v, ans, 0, n - 1);

    return ans;
}


int getCount(vector<int> coders) {
    int n = coders.size();
    vector<int> reverseArr = coders;
    reverse(reverseArr.begin(), reverseArr.end());
    vector<int> lowRight = constructLowerArray(coders, n);
    vector<int> lowLeft = constructLowerArray(reverseArr, n);

    int highRight[n], highLeft[n];

    for(int i = 1; i < n - 1; i++) {
        highLeft[i] = i - lowLeft[i];
        highRight[i] = n - 1 - i - lowRight[i];
    }

    ll totalCount = (ll)n * (ll)(n - 1) * (ll)(n - 2) / 6;
    for(int i = 1; i < n - 1; i++) {
        totalCount -= highRight[i] * highLeft[i];
        totalCount -= lowRight[i] * lowLeft[i];
    }

    return totalCount;
}

int main() {
    vector<int> x = {3,1,4,2};
    int ans = getCount(x);
    cout << ans << '\n';
    return 0;
}