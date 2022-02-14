#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str)
{
	vector<int> vec;
	istringstream iss(str);
	char skip;
	int n;

	while (iss >> n)
	{
		vec.push_back(n);
		iss >> skip;
	}
	return vec;
}

int main()
{
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);

	for (int integer : integers)
		cout << integer << "\n";

	return 0;
}
