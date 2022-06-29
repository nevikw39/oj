#include "2301.hpp"

int main()
{
    vector<vector<char>> a = {{'e', '3'}, {'t', '7'}, {'t', '8'}}, b = {{'o', '0'}}, c = {{'e', '3'}, {'t', '7'}, {'t', '8'}, {'d', 'b'}, {'p', 'b'}};
    Solution sln;
    cout << sln.matchReplacement("fool3e7bar", "leet", a) << '\n'
         << sln.matchReplacement("fooleetbar", "f00l", b) << '\n'
         << sln.matchReplacement("Fool33tbaR", "leetd", c) << '\n' << '\n';
    return 0;
}
