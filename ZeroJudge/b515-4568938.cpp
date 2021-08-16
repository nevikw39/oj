#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<string, char> m;
	m[".-"] = 'A';
	m["-..."] = 'B';
	m["-.-."] = 'C';
	m["-.."] = 'D';
	m["."] = 'E';
	m["..-."] = 'F';
	m["--."] = 'G';
	m["...."] = 'H';
	m[".."] = 'I';
	m[".---"] = 'J';
	m["-.-"] = 'K';
	m[".-.."] = 'L';
	m["--"] = 'M';
	m["-."] = 'N';
	m["---"] = 'O';
	m[".--."] = 'P';
	m["--.-"] = 'Q';
	m[".-."] = 'R';
	m["..."] = 'S';
	m["-"] = 'T';
	m["..-"] = 'U';
	m["...-"] = 'V';
	m[".--"] = 'W';
	m["-..-"] = 'X';
	m["-.--"] = 'Y';
	m["--.."] = 'Z';
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	while (n--)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> s)
			cout << m[s];
		cout << endl;
	}
	return 0;
}
