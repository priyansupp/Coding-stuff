#include<bits/stdc++.h>
using namespace std;

int arr[100];   // all elements' default value is 0
bool comp[78];  // all elements' default value is false

int main()
{
//     double x = 12113.323242422132833;
//     printf("%.10f\n", x);           // prints the value of x with 10 decimal places:
//     cout << setprecision(15) << x << '\n';      // prints with 15 digits of precision
//     cout << setprecision(2);      // prints with 2 digits of precision
//     cout << x << '\n';

//     // It is risky to compare floating point numbers with the == operator, because it is possible that the values should be equal but they are not because of precision errors. A better way to compare floating point numbers is to assume that two numbers are equal if the difference between them is less than ε, where ε is a small number.
//     if (abs(a-b) < 1e-9) {
//         // a and b are equal
//     }

//     string s;
//     getline(cin, s);     // read a whole line from the input, possibly containing spaces

    // ALL DEFAULT VALUES ARE 0/FALSE/EMPTY STRING in vectors.
    vector<int>v(5);     
    cout << v[2] << '\n';
    vector<string>s(40, "hello");
    cout << s[3] << '\n';
    int a[20];          // stores garbage values
    cout << a[3] << " " << a[7] << '\n';

    return 0;   
}