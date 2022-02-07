#include<bits/stdc++.h>

using namespace std;

class Box
{
	int length_ = 0, breadth_ = 0, height_ = 0;
public:
	Box() = default;

	Box(int length, int breadth, int height) :
		length_(length), breadth_(breadth), height_(height) { }

	int getLength() const { return length_; }
	int getBreadth() const { return breadth_; }
	int getHeight() const { return height_; }
	long long CalculateVolume() { return static_cast<long long>(length_ * breadth_) * height_; }
};

bool operator<(const Box& a, const Box& b)
{
	int aLen = a.getLength(), bLen = b.getLength();
	int aBrd = a.getBreadth(), bBrd = b.getBreadth();
	int aHgt = a.getHeight(), bHgt = b.getHeight();

	return aLen < bLen ||
		aLen == bLen && aBrd < bBrd ||
		aLen == bLen && aBrd == bBrd && aHgt < bHgt;
}

ostream& operator<<(ostream& os, Box& b)
{
	os << b.getLength() << ' ' << b.getBreadth() << ' ' << b.getHeight();
	return os;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
				cout << "Lesser\n";
			else
				cout << "Greater\n";
		}
		if (type == 4)
			cout << temp.CalculateVolume() << endl;

		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}
	}
}

int main()
{
	check2();
}
