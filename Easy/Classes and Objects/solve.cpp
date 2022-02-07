#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Student
{
	vector<int> scores;
public:
	Student() { }

	void input()
	{
		scores = vector<int>(5);

		for (int i = 0; i < 5; ++i)
		{
			cin >> scores[i];
		}
	}

	int calculateTotalScore()
	{
		int total = 0;

		for (int score : scores)
		{
			total += score;
		}

		return total;
	}
};

int main()
{
	int n; // number of students
	cin >> n;
	Student* s = new Student[n]; // an array of n students

	for (int i = 0; i < n; i++)
		s[i].input();

	// calculate kristen's score
	int kristen_score = s[0].calculateTotalScore();

	// determine how many students scored higher than kristen
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		int total = s[i].calculateTotalScore();

		if (total > kristen_score)
			ans++;
	}

	cout << ans;

	return 0;
}
