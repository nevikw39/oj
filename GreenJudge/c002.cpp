#include <iostream>  
#pragma GCC optimize("O3")  
using namespace std;  
int main()  
{  
    cin.tie(0);  
    cout.tie(0);  
    ios::sync_with_stdio(0);
    int n = 0;
    const int arr[] = {0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000};
    string s, t;
    cin >> s >> t;
    for (int i = 8; i >= 3; i--)
        if (string(s.rbegin(), s.rbegin() + i) == string(t.rbegin(), t.rbegin() + i))
        {
            cout << arr[i];
            return 0;
        }
    cout << 0;
    return 0;  
}  