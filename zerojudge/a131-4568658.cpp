#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char, char> m;
	m['B'] = '1';
	m['P'] = '1';
	m['F'] = '1';
	m['V'] = '1';
	m['C'] = '2';
	m['S'] = '2';
	m['K'] = '2';
	m['G'] = '2';
	m['J'] = '2';
	m['Q'] = '2';
	m['X'] = '2';
	m['Z'] = '2';
	m['D'] = '3';
	m['T'] = '3';
	m['L'] = '4';
	m['M'] = '5';
	m['N'] = '5';
	m['R'] = '6';
	string s;
	cout << "         NAME                     SOUNDEX CODE\n";
	while (cin >> s)
	{
		char t = 0;
		cout << "         " << s;
		for (int i = s.length(); i < 25; i++)
			cout << ' ';
		cout << s.front();
		for (auto c = s.begin() + 1; c != s.end(); c++)
			if (m[*c] && m[*(c - 1)] != m[*c])
			{
				if (++t > 3)
					break;
				cout << m[*c];
			}
		for (char i = t; i < 3; i++)
			cout << '0';
		cout << endl;
	}
	cout << "                   END OF OUTPUT\n";
	return 0;
}
