// https://www.youtube.com/watch?v=G9QTjWtK_TQ
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

// template for geometry problems
typedef long long ll;
struct P{
    ll x, y;
    P() {}
    P(ll x, ll y) : x(x), y(y) {}
    void read() {
        cin >> x >> y;
    }
    P operator-(const P &b) const {
        return P(x - b.x, y - b.y);
    }
    P operator+(const P &b) const {
        return P(x + b.x, y + b.y);
    }
    void operator-=(const P &b) {
        x -= b.x;
        y -= b.y;
    }
    void operator+=(const P &b) {
        x += b.x;
        y += b.y;
    }
    ll cross_product(const P &a, const P &b) const {
        return a.x * b.y - a.y * b.x;
    }
    ll operator*(const P &a) const {
        return cross_product(*this, a);
    }
    ll triangle(const P &a, const P &b) const {
        // *this, a, b forms a triangle and we have to return the cross product of two sides taking *this as origin. Area < 0 if a lies to the left of b(taking *this as origin) and vice-versa
        return (a - *this) * (b - *this);     // returns double the area of the triangle
    }
};

void solve() {
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();

    // when p1->p2 is parallel to p3->p4, cross_product = 0
    if((p2 - p1) * (p4 - p3) == 0) {
        // when p1-p2 is non-collinear to p3-p4
        if(p1.triangle(p2, p3) != 0) {
            cout << "NO\n";
            return;
        }

        // collinear :
        // now if the BOUNDING BOX of p1, p2 and p3, p4 do not overlap then NO else YES
        for(int i = 0; i < 2; i++) {
            if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                cout << "NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        // collinear and overlapping
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < 2; i++) {
        // for line segment p1->p2 we check if the line segment p3->p4 lies completely to the left or completely to the right, then NO.  Or if it lies half-half then we check for p3->p4 if p1->p2 lies completely to right or left or half-half. This we do just by swapping the values.
        ll res1 = p1.triangle(p3, p2), res2 = p1.triangle(p4, p2);
        // res1 < 0 p3 lies to the left of p1->p2. res1 > 0 p4 lies to the right of p1->p2
        // res2 < 0 p4 lies to the left of p1->p2. res2 > 0 p4 lies to the right of p1->p2
        if((res1 > 0 && res2 > 0) || (res1 < 0 && res2 < 0)) {
            cout << "NO\n";
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES\n";
}


int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}