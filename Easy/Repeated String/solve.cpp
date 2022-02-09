#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

long repeatedString(string s, long n)
{
	long countA = 0;

	for (char c : s)
		if (c == 'a')
			++countA;

	long sections = n / s.length();
	long diff = n - (s.length() * sections);
	long countExtra = 0;

	for (int i = 0; i < diff; ++i)
		if (s[i] == 'a')
			++countExtra;

	return countA * sections + countExtra;
}

int main()
{
	string s;
	getline(cin, s);

	string n_temp;
	getline(cin, n_temp);

	long n = stol(ltrim(rtrim(n_temp)));

	long result = repeatedString(s, n);

	cout << result << "\n";

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
