#include "1408.hpp"

int main()
{
    vector<string> a{"mass", "as", "hero", "superhero"}, b{"leetcode", "et", "code"}, c{"blue", "green", "bu"};
    Solution sln;
    assert(sln.stringMatching(a) == (vector<string>{"as", "hero"}));
    assert(sln.stringMatching(b) == (vector<string>{"et","code"}));
    assert(sln.stringMatching(c) == vector<string>());
    return 0;
}
