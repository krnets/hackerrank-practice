#include <bits/stdc++.h>

using namespace std;

int camelcase(string s)
{
	return 1 + count_if(s.begin(), s.end(), [](char c) { return isupper(c); });
}

int main()
{
	string s;
	getline(cin, s);

	int result = camelcase(s);

	cout << result << "\n";

	return 0;
}
