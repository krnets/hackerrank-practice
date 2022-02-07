#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s)
{
	int length = s.size();
	bool before_midday = s[length - 2] == 'A';

	int hours = stoi(s.substr(0, 2));

	string hh = to_string(before_midday ? hours % 12 : (hours == 12 ? 12 : (hours + 12) % 24));

	if (hh.size() == 1)
		hh.insert(0, "0");

	s.erase(0, 2);
	s = hh + s;
	s.erase(length - 2, 2);

	return s;
}

int main()
{
	string s;
	getline(cin, s);

	cout << timeConversion(s);

	return 0;
}
