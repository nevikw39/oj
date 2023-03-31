#include "1444.hpp"

int main()
{
    vector<string> a{"A..", "AAA", "..."}, b{"A..", "AA.", "..."}, c{"A..", "A..", "..."}, d{".A","AA","A."};
    Solution sln;
    cout << sln.ways(a, 3) << '\n'
         << sln.ways(b, 3) << '\n'
         << sln.ways(c, 1) << '\n'
         << sln.ways(d, 3) << '\n';
    return 0;
}
