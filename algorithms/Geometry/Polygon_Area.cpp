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


int main() {
    int n;
    cin >> n;
    vector<P> polygon(n);
    for(P &p : polygon) p.read();
    ll ans = 0;
    // fix a vertex and calculate area of triangles formed by consecutive vectors from fixed vertex to the consecutive vertices. Add them with sign. Adding with sign is necessry for it to work with concave polygons.
    // in concave polygons, when it is vector is going clockwise area would be negative, but when there is a concave angle(vertex), the vector would move counter-clockwise hence the area will be positive and would cancel the outside area. Draw and check
    for(int i = 1; i < n; i++) {
        ans += polygon[0].triangle(polygon[i], polygon[(i + 1 >= n ? 0 : i + 1)]);
    }
    cout << abs(ans);           // 2*area of polygon is printed, as asked in question. Area of polygon = abs(area) / 2.0
    return 0;
}
