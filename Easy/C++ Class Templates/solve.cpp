#include <iostream>

using namespace std;

#define endl '\n';

template <class T>
class AddElements
{
	T element_;
public:
	AddElements(T element) : element_(element) { }

	T add(T other) { return element_ + other; }
};

template <>
class AddElements<string>
{
	string s_;
public:
	AddElements(string& str) : s_(str) { }

	string& concatenate(string& other)
	{
		s_.append(other);

		return s_;
	}
};

int start_up()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}

int static r = start_up();


int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		string type;
		cin >> type;
		if (type == "float")
		{
			double element1, element2;
			cin >> element1 >> element2;
			AddElements<double> myfloat(element1);
			cout << myfloat.add(element2) << endl;
		}
		else if (type == "int")
		{
			int element1, element2;
			cin >> element1 >> element2;
			AddElements<int> myint(element1);
			cout << myint.add(element2) << endl;
		}
		else if (type == "string")
		{
			string element1, element2;
			cin >> element1 >> element2;
			AddElements<string> mystring(element1);
			cout << mystring.concatenate(element2) << endl;
		}
	}
	return 0;
}
