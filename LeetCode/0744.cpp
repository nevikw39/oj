#include "0744.hpp"

int main()
{
    Solution sln;
    assert(sln.nextGreatestLetter({'c', 'f', 'j'}, 'a') == 'c');
    assert(sln.nextGreatestLetter({'c', 'f', 'j'}, 'c') == 'f');
    assert(sln.nextGreatestLetter({'x', 'x', 'y', 'y'}, 'z') == 'x');
    return 0;
}
