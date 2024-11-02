#include "2490.hpp"

int main()
{
    Solution sln;
    assert(sln.isCircularSentence("leetcode exercises sound delightful"));
    assert(sln.isCircularSentence("eetcode"));
    assert(!sln.isCircularSentence("Leetcode is cool"));
    return 0;
}
