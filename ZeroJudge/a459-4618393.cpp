#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;
int main()
{
	array<char, 240> Brain;
	unsigned char Ptr = 0;
	map<string, function<void()>> m;
	m["(>OwO)>u~(/OwO)/nya~"] = [&] { Ptr++; };
	m["(>OwO)>u~!(/OwO)/nya~!"] = [&] { Brain[Ptr]++; };
	m["(>OwO)>u~!!(/OwO)/nya~!!"] = [&] { Ptr--; };
	m["(>OwO)>u~!!!(/OwO)/nya~!!!"] = [&] { Brain[Ptr]--; };
	m["CHAOS"] = [&]() {
		vector<function<void()>> v;
		string s;
		cin >> s;
		while (cin >> s && s != "I")
		{
			if (s == "CHAOS")
			{
				cin >> s;
				vector<function<void()>> w;
				while (cin >> s && s != "I")
					w.push_back(m[s]);
				v.push_back([&, w] {
					while (Brain[Ptr])
						for (auto i : w)
							i();
				});
				cin >> s >> s;
			}
			else
				v.push_back(m[s]);
		}
		cin >> s >> s;
		while (Brain[Ptr])
			for (auto i : v)
				i();
	};
	m["Let's\\(OwO)/nya~"] = [&]() {
		cout.put(Brain[Ptr]);
	};
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s)
		m[s]();
	return 0;
}
