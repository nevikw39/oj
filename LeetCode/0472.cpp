#include "0472.hpp"

int main()
{
    vector<string> a{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"}, b{"cat", "dog", "catdog"};
    Solution sln;
    for (const auto &i : sln.findAllConcatenatedWordsInADict(a))
        cout << i << ' ';
    cout << '\n';
    for (const auto &i : sln.findAllConcatenatedWordsInADict(b))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
