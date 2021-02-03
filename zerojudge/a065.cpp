#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string in;
    while (cin >> in)
    {
        string out;
        for (int i = 1; i < in.length(); i++)
            out += to_string(abs(in[i] - in[i - 1]));
        cout << out << endl;
    }
    return 0;
}
