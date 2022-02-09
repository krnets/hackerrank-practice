#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

int alternatingCharacters(string s)
{
	int ans = 0;
	char prev = s.front();

	for (int i = 1; i < s.length(); ++i)
	{
		char curr = s[i];

		if (curr == prev)
		{
			++ans;
		}
		prev = curr;
	}
	return ans;
}

int main()
{
	string q_temp;
	getline(cin, q_temp);

	int q = stoi(ltrim(rtrim(q_temp)));

	for (int q_itr = 0; q_itr < q; q_itr++)
	{
		string s;
		getline(cin, s);

		int result = alternatingCharacters(s);

		cout << result << "\n";
	}

	return 0;
}

string ltrim(const string& str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}