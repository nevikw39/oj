#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int arr[15];
    for (int i = 0; i < 15; i++)
        cin >> arr[i];
    double m5_p = 0, m10_p = 0;
    for (int i = 0; i < 5; i++)
        m10_p += arr[9 - i], m5_p += arr[9 - i];
    for (int i = 5; i < 10; i++)
        m10_p += arr[9 - i];
    m5_p /= 5;
    m10_p /= 10;
    for (int i = 10; i < 15; i++)
    {
        double m5 = 0, m10 = 0;
        for (int j = 0; j < 5; j++)
            m10 += arr[i - j], m5 += arr[i - j];
        for (int j = 5; j < 10; j++)
            m10 += arr[i - j];
        m5 /= 5;
        m10 /= 10;
        cout << arr[i];
        if (m5 > m5_p && m10 > m10_p && arr[i] > m5 && m5 > m10 && arr[i] < 1.2 * m10)
            cout << 'B';
        else if (arr[i] > 1.2 * m10 || arr[i] < m5 && m5 < m10 || m10 < m10_p)
            cout << 'S';
        else
            cout << 'N';
        cout << ' ';
        m5_p = m5;
        m10_p = m10;
    }
    return 0;
}
