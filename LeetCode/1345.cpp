#include "1345.hpp"

int main()
{
    vector<int> a{100, -23, -23, 404, 100, 23, 23, 23, 3, 404}, b{7}, c{7, 6, 9, 6, 9, 6, 9, 7}, d(5e4, 7);
    Solution sln;
    cout << sln.minJumps(a) << '\n'
         << sln.minJumps(b) << '\n'
         << sln.minJumps(c) << '\n'
         << sln.minJumps(d) << '\n';
    return 0;
}
