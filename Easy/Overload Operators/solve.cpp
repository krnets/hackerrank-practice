//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
	int a, b;

	void input(string s)
	{
		int v1 = 0;
		int i = 0;
		while (s[i] != '+')
		{
			v1 = v1 * 10 + s[i] - '0';
			i++;
		}
		while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
		{
			i++;
		}
		int v2 = 0;
		while (i < s.length())
		{
			v2 = v2 * 10 + s[i] - '0';
			i++;
		}
		a = v1;
		b = v2;
	}
};

Complex operator+(Complex B, Complex C)
{
	Complex A;
	A.a = B.a + C.a;
	A.b = B.b + C.b;

	return A;
}

ostream& operator<<(ostream& os, Complex B)
{
	os << B.a << "+i" << B.b;

	return os;
}

int main()
{
	Complex x, y;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	x.input(s1);
	y.input(s2);
	Complex z = x + y;
	cout << z << endl;
}
