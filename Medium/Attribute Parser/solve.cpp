#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

void performQuery(vector<string>& queries, unordered_map<string, string>& map)
{
	for (string& query : queries)
		if (map.find(query) == map.end())
			cout << "Not Found!" << endl;
		else
			cout << map[query] << endl;
}

void fillAttributeMap(vector<string>& hrml, unordered_map<string, string>& map)
{
	vector<string> tags;

	for (string& line : hrml)
	{
		line.erase(remove(line.begin(), line.end(), '\"'), line.end());
		line.erase(remove(line.begin(), line.end(), '>'), line.end());

		if (line.substr(0, 2) == "</")
			tags.pop_back();

		else
		{
			stringstream ss(line);
			char ch;
			string num_tag, prop, value;

			ss >> ch >> num_tag >> prop >> ch >> value;

			string tag;

			if (tags.empty())
				tag = num_tag;
			else
				tag = tags.back() + "." + num_tag;

			tags.push_back(tag);

			map[tags.back() + "~" + prop] = value;

			while (ss)
			{
				ss >> prop >> ch >> value;

				map[tags.back() + "~" + prop] = value;
			}
		}
	}
}

int main()
{
	int n, q;
	cin >> n >> q;
	cin.ignore();

	vector<string> hrml, queries;
	unordered_map<string, string> map;
	string line;

	while (n--)
	{
		getline(cin, line);
		hrml.push_back(line);
	}
	while (q--)
	{
		getline(cin, line);
		queries.push_back(line);
	}

	fillAttributeMap(hrml, map);
	performQuery(queries, map);

	return 0;
}
