#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s)
{
	if (s.empty())
		return "Empty String";

	if (s.length() >= 2)
	{
		for (int i = 1; i < s.length(); ++i)
		{
			if (s[i - 1] == s[i])
			{
				return superReducedString(s.erase(i - 1, 2));
			}
		}
	}
	return s;
}

int main()
{
	string s;
	getline(cin, s);

	string result = superReducedString(s);

	cout << result << "\n";

	return 0;
}
