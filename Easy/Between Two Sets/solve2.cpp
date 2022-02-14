#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

int gcd(int x, int y) { return y == 0 ? abs(x) : gcd(y, x % y); }
int lcm(int x, int y) { return abs(x * y) / gcd(x, y); }

int getTotalX(vector<int> a, vector<int> b)
{
	int lcm_a = a.front();
	int gcd_b = b.front();

	for (int i = 1; i < a.size(); ++i)
		lcm_a = lcm(a[i], lcm_a);

	for (int i = 1; i < b.size(); ++i)
		gcd_b = gcd(b[i], gcd_b);

	int multiple = lcm_a;
	int count_mults = 0;

	while (multiple <= gcd_b)
	{
		if (gcd_b % multiple == 0)
			++count_mults;

		multiple += lcm_a;
	}

	return count_mults;
}

int main()
{
	string first_multiple_input_temp;
	getline(cin, first_multiple_input_temp);

	vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

	int n = stoi(first_multiple_input[0]);

	int m = stoi(first_multiple_input[1]);

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	string brr_temp_temp;
	getline(cin, brr_temp_temp);

	vector<string> brr_temp = split(rtrim(brr_temp_temp));

	vector<int> brr(m);

	for (int i = 0; i < m; i++)
	{
		int brr_item = stoi(brr_temp[i]);

		brr[i] = brr_item;
	}

	int total = getTotalX(arr, brr);

	cout << total << "\n";

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

vector<string> split(const string& str)
{
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos)
	{
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
