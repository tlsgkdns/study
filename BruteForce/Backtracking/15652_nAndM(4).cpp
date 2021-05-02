#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
void solve(int cur, int d)
{
	if (d == m)
	{
		for (int e : v) cout << e << " ";
		cout << '\n';
		return;
	}

	for (int i = cur; i <= n; i++)
	{
		v[d] = i;
		solve(i, d + 1);
	}
}
int main()
{
	cin >> n >> m; v.resize(m);
	solve(1, 0);
}

// https://www.acmicpc.net/problem/15652