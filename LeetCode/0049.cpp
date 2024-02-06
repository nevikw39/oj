#include "0049.hpp"

int main()
{
    vector<string> a{"eat", "tea", "tan", "ate", "nat", "bat"}, b{""}, c{"a"};
    Solution sln;
    assert(sln.groupAnagrams(b) == vector<vector<string>>({{""}}));
    assert(sln.groupAnagrams(c) == vector<vector<string>>({{"a"}}));
    return 0;
}
