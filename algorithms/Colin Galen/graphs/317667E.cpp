#include<bits/stdc++.h>
using namespace std;


const int N = 1e6;
int Parent[N];
int Size[N];
int nedges[N];

void make(int v){
    Parent[v] = v;
    Size[v] = 1;
    nedges[v] = 0;
}

int find(int v){
    if(v == Parent[v]) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        Parent[b] = Parent[a];
        Size[Parent[a]] += Size[Parent[b]];
        nedges[Parent[a]] += nedges[Parent[b]] + 1;
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    // the idea is every component must have exactly nodes*(nodes-1)/2 edges, i.e every possible edge between nodes, then only it can be reasonable.
    // we can count total number of edges for each component and check if it is equal to total_nodes*(total_nodes - 1) / 2.
    // better to use dsu, to maintain size, and number of edges
    for(int i = 1; i <= n; i++) make(i);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    bool flag = true;
    for(int i = 1; i <= n; i++) {
        if(nedges[Parent[i]] != Size[Parent[i]] * (Size[Parent[i]] - 1) / 2) {
            flag = false;
            break;
        }
    }

    (flag) ? cout << "YES" : cout << "NO";

    return 0;
}