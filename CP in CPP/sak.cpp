#include<bits/stdc++.h>

using namespace std;

struct Point2D {
    int x;
    int y;
};

int ncr(int n, int r) {
    if(r > n - r) {
        r = n - r;
    }
    int ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int solution(vector<Point2D> &A) {
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        unordered_map<double, int>mp;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(A[i].x - A[j].x == 0) {
                mp[INT_MAX]++;
                continue;
            }
            double slope = (double)(A[i].y - A[j].y) / (double)(A[i].x - A[j].x);
            // double trunc(slope);
            int round(slope);
            if(slope == -0) slope = 0;
            cout << slope << " ";
            mp[slope]++;
        }
        for(auto it : mp) {
            if(it.second >= 3) {
                ans += ncr(it.second, 2);
                cout << '\n' << ans << "\n";
                if(ans > 1e9) return -1;
            } 
        }
    }

    return ans / 2;
}

int main(){
    int n;
    cin >> n;
    vector<Point2D> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
    }

    cout << solution(A);

    return 0;
}