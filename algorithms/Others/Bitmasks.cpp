#include<bits/stdc++.h>
using namespace std;

// setting a bit : making it 1
// resetting a bit : making it 0

void showbits(unsigned int x)
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)     // sizeof(int) = 4 bytes, therefore i = 4*8-1 = 31. i  will left shift 31 0's at the first iteration, i.e 1u << i will be 10000000000000000000000000000000 (1 followed by 31 0's)
    {
       putchar(x & (1u << i) ? '1' : '0');    // comparing that digit in x to 1 in 1u << i.
    }
    printf("\n");
}


int main()
{
    int a = 5, b = 9;
    showbits(a);
    // a = 5(00000000000000000000000000000101), b = 9(00000000000000000000000000001001)   
    // Rightmost bit is 0th bit. Rightmost bit where 1 first occurs is LSB and leftmost bit where 1 occurs is MSB.

    // The result is 00000001
    // cout<<"a = " << a <<","<< " b = " << b <<endl;
    // cout << "a & b = " << (a & b) << endl;
  
    // The result is 00001101
    // cout << "a | b = " << (a | b) << endl;
  
    // The result is 00001100
    // cout << "a ^ b = " << (a ^ b) << endl;
  
    // The result is 11111111111111111111111111111010
    // showbits(~(a));
    // cout << "~(" << a << ") = " << (~a) << endl;
  
    // The result is 00010010
    // cout << "b << 1" << " = " << (b << 1) << endl;

    // The result is 00000100
    // cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;

    // cout << (1 << 33) << endl;    // int is upto 2^32 - 1, so left shiting 33 0's makes all the digits 0(integer overflow)
    // cout << (1LL << 33) << endl;  // typecasting 1 from int to long long
    
    // unsigned int x = 1;     // Leftmost is MSB, not a sign bit, so inverting this actually inverts all the value bits.
    signed int y = -78;       // normal int. Leftmost bit is for sign bit(1 for negative, 0 for positive). rest 31 are for value
    // showbits(x);
    // showbits(y);
    // showbits(~(x));
    // showbits(~(y));
    // cout<<"Unsigned Result "<< ~x << '\n';   // all bits are magnitude bits, so it works as expected.
    // cout<<"Signed Result "<< ~y << '\n';     // with signed int the result is always (negative of the number - 1), be the number is negative or positive.
    // A computer operates and deals with negative numbers using 2's complement. So, ~(y) actually calculates 1's complement(inverting all the bits) and not -y. Had the computer worked in 1's complement(although it has drawbacks) then ~(y) would have represented -y in 1's complement world of computer.

    // But in 2's complement world of computer, 2's complement of y will represent -y. 
    // 2's complement of y = -y = 1's complement of y + 1 = ~(y) + 1 => this will represent -y
    // Hence ~(y) = 2's complement of y - 1 = -y - 1
    


    // Bitset: A bitset is an array of bool but each Boolean value is not stored separately instead bitset optimizes the space such that each bool takes 1 bit space only, so space taken by bitset bs is less than that of bool bs[N] and vector bs(N). However, a limitation of bitset is, N must be known at compile time, i.e., a constant (this limitation is not there with vector and dynamic array)




    bitset<10>A;   // A is now 0000000000  // kind of datatype to create numbers by bits
    // cout << A << '\n';                  // prints the bits of A
    // cout << A.to_ulong() << '\n';       // bitset to an unsigned long integer
    // cout << A.to_ullong() << '\n';      // bitset to an unsigned long long integer(when more digits are in bitset, use this)

    // A[0] = 1;        // 0000000001
    // A[4] = 1;        // 0000010001
    // A[7] = 1;        // 0010000000
    bitset<10>B(20);   // B is now 20 in binary with 10 binary digits i.e 0000010100
    // cout << B << "\n";
    bitset<10>C(string("1001"));   // C is initialized with bits of specified binary string
    // cout << C << " has " << C.count() << " number of ones and " << C.size() - C.count() << " number of zeroes." <<'\n';  
    // count outputs number of set bits in C and size outputs total number of bits in binary rep of C. Both are methods of bitset datatype.
    // cout << C.test(0) << " & " << C.test(2) << '\n';   // test(i) method returns 1 if ith bit is set else returns 0
    // .test(i) is actually just performing cout << C & (1 << i);
    C.set();   // sets all bits(makes them 1)
    C.set(2);  // sets 2nd bit 
    C.set(0);  // sets 0th bit
    C.set(3, 0);  // makes 3rd bit as 0
    C.set(4, 1);  // makes 4th bit as 1(i.e sets the 4th bit)
    C.reset();   // resets all bits(makes them 0)
    C.reset(2);  // resets 2nd bit(makes 2nd bit 0) same as C.set(2, 0);
    C.flip();    // flips all bits(0 -> 1  and 1 -> 0)
    C.flip(2);   // flips 2nd bit

    bitset<8>bits(9);
    // cout << bits << " " << ~(bits) << '\n';   // works perfectly with every other logical and bitwise operator.

    // BIT MANIPULATION

    // set a bit in the number ‘num’ 
    int num = 10;           // 1010
    showbits(num);
    num = num | (1 << 2);   // sets the 2nd bit. num is 1110
    showbits(num);

    num &= ~(1 << 2);  // resets the 2nd bit(makes it 0). num is 1010
    num ^= (1 << 2);   // XOR toggles the 2nd bit. 0^1 makes it 1 and 1^1 makes it 0
    if(num & (1 << 2)){  // checks whether 2nd bit is set or unset
        cout << "2nd bit is set" << '\n';
    }

    num = 56;           // 111000
    int x = num, count = 0;

    num = num & (num - 1);   // Stripping off the lowest set bit. num is 110000
    showbits(num);

    while(x){
        x &= (x - 1);        // after total set bits are stripped off one by one from last, x will become 0
        count++;             // actually gives total count of set bits in x.
    }

    num = num & (-num);  // num & (~(num) + 1)... Getting lowest set bit of a number... num is 10000
    showbits(num);


}