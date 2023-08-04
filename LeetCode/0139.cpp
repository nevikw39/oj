#include "0139.hpp"

int main()
{
    vector<string> a{"leet", "code"}, b{"apple", "pen"}, c{"cats", "dog", "sand", "and", "cat"};
    Solution sln;
    cout << sln.wordBreak("leetcode", a) << '\n'
         << sln.wordBreak("applepenapple", b) << '\n'
         << sln.wordBreak("catsandog", c) << '\n';
    return 0;
}
