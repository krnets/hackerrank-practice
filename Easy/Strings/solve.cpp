#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	cout << a.length() << ' ' << b.length() << endl;
	cout << a + b << '\n';
	swap(a.front(), b.front());
	cout << a << ' ' << b << endl;

	return 0;
}
