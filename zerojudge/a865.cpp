#include <iostream>
#include <map>
using namespace std;
int main()
{
    string s;
    map<char, int> m = {
        {'A', 1},
        {'B', 2},
        {'G', 3},
        {'D', 4},
        {'E', 5},
        {'#', 6},
        {'Z', 7},
        {'Y', 8},
        {'H', 9},
        {'I', 0},
        {'K', 20},
        {'L', 30},
        {'M', 40},
        {'N', 50},
        {'X', 60},
        {'O', 70},
        {'P', 80},
        {'Q', 90},
        {'R', 100},
        {'S', 200},
        {'T', 300},
        {'U', 400},
        {'F', 500},
        {'C', 600},
        {'$', 700},
        {'W', 800},
        {'3', 900},
    };
    while (cin >> s)
    {
        if (s == ".")
            break;
        int sum = 0;
        for (char c : s)
            sum += m[c];
        cout << sum << endl;
    }
    return 0;
}
