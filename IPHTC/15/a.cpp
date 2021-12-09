#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000

class BigInt
{
public:
    long long operator[](int i) const { return m[i]; }
    long long &operator[](int i) { return m[i]; }
    BigInt()
    {
        l = 1, m[0] = 0;
        sign = 1;
    }
    friend istream &operator>>(istream &, BigInt &);
    friend ostream &operator<<(ostream &, BigInt);
    BigInt operator+(const BigInt &y);
    BigInt operator-(const BigInt &y);

private:
    long long m[MAX_N];
    int l; //長度
    int sign;
};

#include "a.hpp"

int main()
{
    BigInt a, b;
    while (cin >> a >> b)
    {
        cout << (a + b) << '\n';
        cout << (a - b) << '\n';
    }
    return 0;
}
