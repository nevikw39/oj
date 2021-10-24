#include "2048.hpp"

int main()
{
    Solution sln;
    cout << sln.nextBeautifulNumber(10) << '\n'
         << sln.nextBeautifulNumber(1000) << '\n'
         << sln.nextBeautifulNumber(3000) << '\n'
         << sln.nextBeautifulNumber(1000000) << '\n';
    return 0;
}
