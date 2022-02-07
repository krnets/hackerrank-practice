#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()
#define foreach(v,i) for (int i = 0; i < v.size(); ++i)
#define toStr(r) #r
#define io(v) cin >> v
#define minimum(e, v) e = (e < v) ? e : v
#define maximum(e, v) e = (e > v) ? e : v
#define FUNCTION(name, op)

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	foreach(v, i)
	{
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i)
	{
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) << ' ' << ans;
	return 0;
}
