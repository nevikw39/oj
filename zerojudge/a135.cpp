#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    string s;
    map<string, string> m({{"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"}, {"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"}});
    while (cin >> s && s != "#")
    {
        cout << "Case " << ++n << ": ";
        try
        {
            cout << m.at(s) << endl;
        }
        catch (...)
        {
            cout << "UNKNOWN\n";
        }
    }
    return 0;
}
