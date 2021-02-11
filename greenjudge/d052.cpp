#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    string s;
    short arr[26];
    memset(arr, 0, sizeof(arr));
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (string::iterator it = s.begin(); it != s.end(); it++)
        if (isalpha(*it))
            arr[*it - 'A']++;
    for (char i = 'A'; i <= 'Z'; i++)
        cout << i << ' ';
    cout << '\n';
    for (short i = 0; i < 26; i++)
        cout << arr[i] << ' ';
    return 0;
}
