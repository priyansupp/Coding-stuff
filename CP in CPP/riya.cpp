#include <vector>       // copy pastes the whole of vector library in this file
#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
#include <climits>
using namespace std;    // -> Already built namespace

// int y = 10;     // -> Global namespace
// namespace riya  // -> User defined namespace
// {
//     int x = -10;
//     class Vector {
//     public:
//         int size() {
//             return 6;
//         }
//     };

//     class Fstream {

//     };

//     class Iostream : public riya::Fstream {

//     };

//     Iostream cin, cout;
// }
// using namespace riya;



int f1(int x, int *y) {
    // do something

    return x + *y + 10;
}

void f2(int a[], int n = 1) {   // int *a
    // cout << sizeof(a) << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}


void f3(int *a, int n = 1) {
    // cout << sizeof(a) << '\n';
    // cout << *a << '\n';     // = *(&a[0])
    for(int i = 0; i < n; i++) {
        cout << *(a + i) << ' ' << a[i] << '\n';
    }
    cout << '\n';
}

void f4(vector<int> v) {     // v is a copy of vector passed in f4
    int n = v.size();
    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    // v[1] += 10;         // does not changes the original vector.
    cout << '\n';
}

void f5(vector<int> &v) {      // & means reference of vector not the MA. v is actually e itself just with another name. v is also called alias of e
    for(int x : v) {
        cout << x << ' ';
    }
    // v[1] += 10;         // it changes the original vector.
    cout << '\n';
}

int main() {

    // riya::Vector v;
    // std::cout << x << '\n';
    // cout;

    std::vector<int>b = {4,3,1,4,8,6};
    int size_b = b.size();
    // cout << size_b << '\n';

    int a[6] = {4,3,1,4,8,6};
    // a = &a[0] -> MA of 0th element = MA of the whole array = Name of the array
    // cout << a << ' ' << &a[0] << '\n';
    // &a[3] = &a[0] + 3 * sizeof(int);
    
    // sizeof() => returns size of input in bytes(B)
    // cout << sizeof(int) << ' ' << sizeof(double) << ' ' << sizeof(b) << '\n';
    int size_a = sizeof(a) / sizeof(int);
    // cout << size_a << '\n';
    // cout << sizeof(int*) << '\n';

    // POINTERS
    // int x = 5;
    // int *y = &x;    // int* y = &x; y is a pointer variable(of type int). y stores memory address of x
    // int *z;
    // z = &x;
    // cout << x << ' ' << y << ' ' << &y << '\n'; // &y -> MA of y itself

    // x += 4;
    // cout << x << ' ' << y << '\n';
    
    // cout << *y << '\n';     // dereferencing y -> prints whatever is stored in the MA to which y is pointing to.

    // y += 7;     // it increases the MA pointed by y by 7
    // cout << *y << ' ' << y << '\n';     // prints garbage value

    // double *a1;
    // float *a2;
    // int *a3;
    // char *a4;
    // cout << sizeof(double) << ' ' << sizeof(float) << ' ' << sizeof(int) << ' ' << sizeof(char) << '\n';
    // cout << sizeof(double*) << ' ' << sizeof(float*) << ' ' << sizeof(int*) << ' ' << sizeof(char*) << '\n';
    // 64bits computer -> 8bits
    // 32bits computer -> 4bits

    // FUNCTIONS
    // int c = 1, d = 5;
    // std::cout << f1(c, &d) << '\n';
    // f2(a, 6);
    // f2(a, 6);
    // f3(a, 6);

    // VECTOR
    vector<int>e = {3,2,5,7};
    // f4(e);          // pass by value
    // cout << e[1] << '\n';

    // f5(e);          // pass by reference
    // cout << e[1] << '\n';

    // e.pop_back();
    // e.push_back(1);
    // f4(e);

    // sort(e.begin(), e.end());
    // reverse(e.begin(), e.end());
    // f4(e);

    // sort(e.begin(), e.end(), greater<int>());   // decreasing order
    // f4(e);

    // vector<int>::iterator it = find(e.begin(), e.end(), 5);
    // cout << *it << '\n';
    // int index = it - e.begin();
    // cout << index << '\n';


    // MAP -> {key, value} pairs
    map<int, int>mp;        // pairs sorted by keys and duplicate keys not allowed
    unordered_map<int, string>ump;  // pairs not sorted by keys and duplicate keys not allowed
    multimap<char, bool>mmp;        // pairs sorted by keys and duplicate keys allowed
    unordered_multimap<int, int>ummp;   // pairs not sorted by keys and duplicate keys allowed

    // map<string, int>mpp;
    // mpp["pk"] = 1;
    // mpp["r"] = 2;

    // mp.insert({2, 5});
    // mp.insert({1, 2});
    // mp.insert({3, -10});
    // mp.insert({1, 3});
    // cout << "Value of 1 = " << mp[1] << " and value of 2 = " << mp[2] << '\n';
    // for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    //     cout << (*it).first << ' ' << (*it).second << '\n';
    // }
    // cout << '\n';
    // for(pair<int, int> x : mp) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    // cout << '\n';
    // for(auto x : mp) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }

    // mp[4] = -2;     // {4, -2}
    // mp[4] = 3;      // update mp[4] to 3
    // cout << mp[4] << '\n';

    // int k = 98;
    // // check if key k exists in map or not
    // // cout << mp[k] << '\n';      // -> never use this to check for keys
    // // whenever we use [] operator, the key automatically gets updated.
    // if(mp.find(k) != mp.end()) {
    //     cout << "Key found\n";
    // } else {    // mp.find(k) == mp.end()
    //     cout << "Key not found\n";
    // }


    // ump.insert({2, "riya"});
    // ump.insert({1, "priyanshu"});
    // ump.insert({3, "abc"});
    // ump.insert({1, "lobb"});
    // cout << "Value of 1 = " << ump[1] << " and value of 2 = " << ump[2] << '\n';
    // for(unordered_map<int, string>::iterator it = ump.begin(); it != ump.end(); it++) {
    //     cout << (*it).first << ' ' << (*it).second << '\n';
    // }
    // cout << '\n';
    // for(pair<int, string> x : ump) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    // cout << '\n';
    // for(auto x : ump) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }

    // mmp.insert({'d', false});
    // mmp.insert({'d', true});
    // mmp.insert({'c', true});
    // mmp.insert({'d', false});
    // // cout << "Value of c = " << mmp['c'] << " and value of d = " << mmp['d'] << '\n';
    // for(multimap<char, bool>::iterator it = mmp.begin(); it != mmp.end(); it++) {
    //     cout << (*it).first << ' ' << (*it).second << '\n';
    // }
    // cout << '\n';
    // for(pair<char, bool> x : mmp) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    // cout << '\n';
    // for(auto x : mmp) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }


    
    // FINDING MAXIMUM/MINIMUM FROM ARRAY/VECTOR
    int n = 5;
    int arr[n] = {2,1,3,-2,7};
    // int mini_element = *min_element(arr, arr + n), maxi_element = *max_element(arr, arr + n);
    // cout << mini_element << ' ' << maxi_element << '\n';


    int mini_element = INT_MAX, maxi_element = INT_MIN;
    int min_ind, max_ind;
    // for(int i = 0; i < n; i++) {
    //     if(arr[i] < mini_element) {       // will always be true for i = 0
    //         mini_element = arr[i];
    //         min_ind = i;
    //     }
    //     if(arr[i] > maxi_element) {
    //         maxi_element = arr[i];        // will always be true for i = 0
    //         max_ind = i;
    //     }
    // }
    // cout << mini_element << ' ' << maxi_element << '\n';
    // cout << min_ind << ' ' << max_ind << '\n';

    // min(3,4) => returns 3
    // max(4,10) => returns 10

    for(int i = 0; i < n; i++) {
        mini_element = min(mini_element, arr[i]);
        maxi_element = max(maxi_element, arr[i]);
    }
    // cout << mini_element << ' ' << maxi_element << '\n';

    return 0;
}
