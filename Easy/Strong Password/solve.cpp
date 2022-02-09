#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

int minimumNumber(int n, string password)
{
	constexpr int minimum_password_len = 6;
	int len = password.length();
	bool has_digit = false;
	bool has_lowercase = false;
	bool has_uppercase = false;
	bool has_special_char = false;
	string special_characters = "!@#$%^&*()-+";

	for (char c : password)
	{
		if (isalpha(c))
		{
			if (isupper(c))
				has_uppercase = true;
			else
				has_lowercase = true;
		}
		else if (isalnum(c))
			has_digit = true;
		else if (special_characters.find(c) != string::npos)
			has_special_char = true;
	}

	int missing = !has_digit + !has_lowercase + !has_uppercase + !has_special_char;

	return max(minimum_password_len - len, missing);
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string password;
	getline(cin, password);

	int answer = minimumNumber(n, password);

	cout << answer << "\n";

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
