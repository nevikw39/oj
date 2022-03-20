#include "2211.hpp"

int main()
{
    Solution sln;
    cout << sln.countCollisions("RLRSLL") << '\n'
         << sln.countCollisions("LLRR") << '\n'
         << sln.countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR") << '\n';
    return 0;
}
