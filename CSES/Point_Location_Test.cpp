// https://www.youtube.com/watch?v=G9QTjWtK_TQ
#include<bits/stdc++.h>
using namespace std;

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
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p2 -= p1;
    p3 = p3 - p1;
    ll res = p3 * p2;
    if(res < 0) cout << "LEFT";            // res < 0 means p3 is left of p2 => first point is to the left of second point.
    else if(res > 0) cout << "RIGHT";
    else cout << "TOUCH";
    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}