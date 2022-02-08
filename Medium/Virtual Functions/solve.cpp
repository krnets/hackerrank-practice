#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Person
{
protected:
	int age;
	string name;
public:
	Person() = default;

	virtual void putdata()
	{
	}

	virtual void getdata()
	{
	}

	virtual ~Person() = default;
};

class Professor : public Person
{
	int publications_, cur_id_;
	static int id;
public:
	Professor()
	{
		id++;
		cur_id_ = id;
	}

	void getdata() { cin >> name >> age >> publications_; }

	void putdata()
	{
		cout << name << " " << age << " ";
		cout << publications_ << " " << cur_id_ << endl;
	}

	~Professor()
	{
	}
};

class Student : public Person
{
	const int kMax = 6;
	int* marks = new int[kMax];
	int cur_id_;
	static int id;
public:
	Student()
	{
		++id;
		cur_id_ = id;
	}

	void getdata()
	{
		cin >> name >> age;

		for (int i = 0; i < kMax; ++i)
			cin >> marks[i];
	}

	void putdata()
	{
		cout << name << " " << age << " ";

		int sum = 0;

		for (int i = 0; i < kMax; ++i)
			sum += marks[i];

		cout << sum << " " << cur_id_ << endl;
	}

	~Student()
	{
		delete[] marks;
	}
};

int Professor::id = 0;
int Student::id = 0;

int main()
{
	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person* per[n];

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		if (val == 1)
		{
			// If val is 1 current object is of type Professor
			per[i] = new Professor;
		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.
	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;
}
