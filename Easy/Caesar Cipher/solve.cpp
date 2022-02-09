#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

string caesarCipher(string s, int k)
{
	for (char& c : s)
	{
		if (isalpha(c))
		{
			if (isupper(c))
			{
				c = (c - 'A' + k) % 26 + 'A';
			}
			else
			{
				c = (c - 'a' + k) % 26 + 'a';
			}
		}
	}
	return s;
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string s;
	getline(cin, s);

	string k_temp;
	getline(cin, k_temp);

	int k = stoi(ltrim(rtrim(k_temp)));

	string result = caesarCipher(s, k);

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
