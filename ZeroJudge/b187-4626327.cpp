#include <string>
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cout << "十六進位表示法  相對應的十進位表示法\n";
	while (cin >> s)
		cout << "      " << s << "                 " << stoi(s, 0, 16) << endl;
	return 0;
}
