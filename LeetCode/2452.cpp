#include "2452.hpp"

int main()
{
    Solution sln;
    assert(sln.twoEditWords({"word", "note", "ants", "wood"}, {"wood", "joke", "moat"}) == vector<string>({"word", "note", "wood"}));
    assert(sln.twoEditWords({"yes"}, {"not"}) == vector<string>({}));
    return 0;
}
