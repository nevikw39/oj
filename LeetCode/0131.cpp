#include "0131.hpp"

int main()
{
    Solution sln;
    for (auto i : sln.partition("aab"))
    {
        copy(ALL(i), ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    cout << '\n';
    for (auto i : sln.partition("a"))
    {
        copy(ALL(i), ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    return 0;
}
