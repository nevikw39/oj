#include "2000.hpp"

int main()
{
    Solution sln;
    cout << sln.reversePrefix("abcdefd", 'd') << '\n'
         << sln.reversePrefix("xyxzxe", 'z') << '\n'
         << sln.reversePrefix("abcd", 'z') << '\n';
    return 0;
}
