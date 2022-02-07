#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, q;
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	cin >> q;

	while (q--)
	{
		int y;
		cin >> y;
		auto it = lower_bound(vec.begin(), vec.end(), y);

		if (*it == y)
			cout << "Yes " << 1 + distance(vec.begin(), it) << '\n';
		else
			cout << "No " << 1 + distance(vec.begin(), it) << '\n';
	}

	return 0;
}
