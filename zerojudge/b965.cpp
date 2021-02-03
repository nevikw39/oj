#include <algorithm>
#include <iostream>
#include <vector>
#define rr ((isRotate ? c : r))
#define cc ((isRotate ? r : c))
//#define rotate3(b, r, c) rotate(rotate(rotate(b, r, c), r, c), r, c)
using namespace std;
typedef vector<int> ivec;
typedef vector<ivec> martix;
martix flip(martix b, int r, int c)
{
    reverse(b.begin(), b.end());
    return b;
}
martix rotate(martix b, int r, int c)
{
    martix a(c, ivec(r, 0));
    b = flip(b, r, c);
    for (auto i : b)
        reverse(i.begin(), i.end());
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            a[i][j] = b[j][i];
    for (int i = 0; i < c; i++)
        reverse(a[i].begin(), a[i].end());
    return flip(a, c, r);
}
int main()
{
    int r, c, m;
    while (cin >> r >> c >> m)
    {
        ivec a(m, 0);
        bool isRotate = false;
        martix mar(r, ivec(c, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> mar[i][j];
        for (int i = 0; i < m; i++)
            cin >> a[i];
        reverse(a.begin(), a.end());
        for (auto i : a)
        {
            if (i == 1)
                mar = flip(mar, rr, cc);
            else
            {
                mar = rotate(mar, rr, cc);
                isRotate = !isRotate;
            }
        }
        cout << rr << " " << cc << endl;
        for (auto i : mar)
        {
            for (int j = 0; j < i.size(); j++)
            {
                cout << i[j];
                if (j != i.size() - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
