#include "0438.hpp"

int main()
{
    Solution sln;
    for (auto &&i : sln.findAnagrams("cbaebabacd", "abc"))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.findAnagrams("abab", "ab"))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa"))
        cout << i << '\n';
    return 0;
}
