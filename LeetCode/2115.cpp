#include "2115.hpp"

int main()
{
    vector<string> a0 = {"bread"}, b0 = {"ju", "fzjnm", "x", "e", "zpmcz", "h", "q"}, a2 = {"yeast"}, b2 = {"f", "hveml", "cpivl", "d"};
    vector<vector<string>> a1 = {{"yeast", "flour"}}, b1 = {{"d"}, {"hveml", "f", "cpivl"}, {"cpivl", "zpmcz", "h", "e", "fzjnm", "ju"}, {"cpivl", "hveml", "zpmcz", "ju", "h"}, {"h", "fzjnm", "e", "q", "x"}, {"d", "hveml", "cpivl", "q", "zpmcz", "ju", "e", "x"}, {"f", "hveml", "cpivl"}};
    Solution sln;
    for (auto &&i : sln.findAllRecipes(a0, a1, a2))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.findAllRecipes(b0, b1, b2))
        cout << i << '\n';
    cout << '\n';
    return 0;
}
