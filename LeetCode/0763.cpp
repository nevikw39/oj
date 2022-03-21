#include "0763.hpp"

int main()
{
    Solution sln;
    for (auto &&i : sln.partitionLabels("ababcbacadefegdehijhklij"))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.partitionLabels("eccbbbbdec"))
        cout << i << '\n';
    return 0;
}
