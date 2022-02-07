#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int x : vec)
		cout << x << ' ';

	return 0;
}
