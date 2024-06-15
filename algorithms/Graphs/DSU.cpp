#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int Parent[N];
int Size[N];

void make(int v){               // makes individual set of given node
    Parent[v] = v;
    Size[v] = 1;
}

// int find(int v){                // finds topmost parent of given node
//     if(v == Parent[v]) return Parent[v];// i.e when v is parent of itself, topmost parent.
//     return find(Parent[v]);

//     // Iterative method:
//     // while (v != parent[v]){
//     //     v = parent[v];
//     // }
//     // return v;
// }

// Path compression
int find(int v){
    if(v == Parent[v]) return Parent[v];
    return Parent[v] = find(Parent[v]);     // assigns parent[v] directly to topmost parent.
}

// void Union(int a, int b){       // performs union of two nodes by unifying their parent.
//     a = find(a);
//     b = find(b);
//     if(a != b){
//         parent[b] = a;
//     }
// }

// Union by size
void Union(int a, int b){       // performs union of two nodes by unifying their parent.
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]){  // a - left tree, b - right tree. Always joining right(small) tree under left(big).
            swap(a, b);
        }
        Parent[b] = a;
        Size[a] += Size[b];
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) make(i);        // in 1 based indexing, node 0 is not included
    for(int i = 1; i <= n; i++) cout << find(i) << " ";
    Union(3, 4);
    Union(5, 6);
    Union(3, 8);
    Union(3, 7);
    Union(5, 7);
    Union(2, 1);
    Union(4, 6);
    for(int i = 1; i <= n; i++) cout << find(i) << " ";
    // cout << find(4) << '\n';
    return 0;
}

