#include<bits/stdc++.h>
using namespace std;

// set(i, v) -> a[i] = v
// sum(l, r) -> sum(a[i]) for i=l...r-1


struct segtree {
    int size;
    vector<long long>sums;                  // array describing the segtree
    
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;          // increases size to nearest power of 2 (>= n), to make leaf nodes as power of 2
        sums.assign(2 * size, 0);           // we initialize the segtree with double the size of the leaf nodes(so as to make the whole tree, until root, fit in the array)
    }

    // update
    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {      // leaf
            sums[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return 0;        // no overlap
        if(lx >= l && rx <= r) return sums[x];  // complete overlap

        // partial overlap
        int mid = (lx + rx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, mid);
        long long s2 = sum(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

};


int main() {
    int n, m;
    cin >> n >> m;
    struct segtree st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }
    return 0;
}