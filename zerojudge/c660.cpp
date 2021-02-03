#include <iostream>
#include <string>
using namespace std;
int main()
{
    string in;
    while (getline(cin, in))
    {
        string outs[in.length()];
        for (char &c : in)
        {
            int i = &c - in.c_str();
            if (c == ' ')
                continue;
            for (char &d : in)
                outs[i].push_back(i == &d - in.c_str() ? toupper(d) : tolower(d));
        }
        for (auto s : outs)
        {
            if (s == "")
                continue;
            cout << s << endl;
        }
    }
    return 0;
}
