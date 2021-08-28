#include "1980.hpp"

int main()
{
    vector<string> a = {"01","10"}, b = {"00","01"}, c = {"111","011","001"};
    Solution sln;
    cout << sln.findDifferentBinaryString(a) << '\n'
         << sln.findDifferentBinaryString(b) << '\n'
         << sln.findDifferentBinaryString(c) << '\n';
    return 0;
}
