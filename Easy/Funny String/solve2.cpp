#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

string funnyString(string s)
{
	int len = s.length();

	vector<int> vecA, vecB;

	for (int i = 1; i < len; ++i)
	{
		int x = abs(s[i] - s[i - 1]);

		vecA.push_back(x);

		int y = abs(s[len - i] - s[len - i - 1]);

		vecB.push_back(y);
	}

	return vecA == vecB ? "Funny" : "Not Funny";
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

		string result = funnyString(s);

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
