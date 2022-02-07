#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int T;
	cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;

	while (T--)
	{
		double A, B, C;
		cin >> A >> B >> C;

		cout << left << hex << showbase << nouppercase;
		cout << (long)A << endl;

		cout << right << setw(15) << setfill('_') << showpos;
		cout << fixed << setprecision(2) << B << endl;

		cout << scientific << uppercase << noshowpos;
		cout << setprecision(9) << C << endl;
	}
	return 0;
}
