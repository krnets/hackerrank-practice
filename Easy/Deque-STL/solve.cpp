#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void printKMax(vector<int>& vec, int n, int k)
{
    deque<int> qi;

    for (int i = 0; i < k; ++i)
    {
        while (!qi.empty() && vec[qi.back()] <= vec[i])
            qi.pop_back();

        qi.push_back(i);
    }

    for (int i = k; i < n; ++i)
    {
        cout << vec[qi.front()] << " ";

        while (!qi.empty() && qi.front() <= i - k)
            qi.pop_front();

        while (!qi.empty() && vec[qi.back()] <= vec[i])
            qi.pop_back();

        qi.push_back(i);
    }

    cout << vec[qi.front()] << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);

        for (int i = 0; i < n; i++)
            cin >> vec[i];

        printKMax(vec, n, k);
    }
    return 0;
}
