#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	int x, start, end;
	cin >> x >> start >> end;
	--x;
	--start;
	--end;
	vec.erase(vec.begin() + x);
	vec.erase(vec.begin() + start, vec.begin() + end);

	cout << vec.size() << '\n';

	for (int x : vec)
		cout << x << ' ';

	return 0;
}
