#include "0127.hpp"

int main()
{
    vector<string> a = {"hot", "dot", "dog", "lot", "log", "cog"}, b = {"hot", "dot", "dog", "lot", "log"}, c = {"hot", "dog", "dot"};
    Solution sln;
    cout << sln.ladderLength("hit", "cog", a) << '\n'
         << sln.ladderLength("hit", "cog", b) << '\n'
         << sln.ladderLength("hot", "dog", c) << '\n';
    return 0;
}
