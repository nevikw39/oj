#include "1750.hpp"

int main()
{
    Solution sln;
    cout << sln.minimumLength("ca") << '\n'
         << sln.minimumLength("cabaabac") << '\n'
         << sln.minimumLength("aabccabba") << '\n'
         << sln.minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb") << '\n';
    return 0;
}
