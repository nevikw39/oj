#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s[] = {"�U", "��", "��", "��", "��", "��", "��", "��", "�s", "�D", "��", "��"};
	short n;
	while (cin >> n)
	{
		n > 0 ? n += 99 : n += 100;
		cout << s[n % 12] << endl;
	}
	return 0;
}
