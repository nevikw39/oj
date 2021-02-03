#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, t = 0;
    double sum = 0;
    vector<int> rv(5);
    while (cin >> n)
    {
        if (!n)
            break;
        rv[n - 1]++;
        t++;
    }
    for (int i = 5; i; i--)
    {
        cout << i << " (" << setw(2) << rv[i - 1] << ") |";
        for (int j = 0; j < rv[i - 1]; j++)
            cout << '=';
        cout << endl;
        sum += rv[i - 1] * i;
    }
    cout << "Average rating: " << fixed << setprecision(4) << sum / t << endl;
    return 0;
}
