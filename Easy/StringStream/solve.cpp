#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str)
{
	vector<int> vec;
	istringstream iss(str);
	string token;

	while (getline(iss, token, ','))
		vec.push_back(stoi(token));

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
