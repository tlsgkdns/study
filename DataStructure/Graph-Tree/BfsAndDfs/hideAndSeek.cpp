#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int hide(int n, int m)
{
	queue<pair<int, int>> q;
	vector<bool> v(100001, false);
	int ans = 0;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		if (f < 0 || f > 100000) continue;
		if (v[f]) continue;
		v[f] = true;
		if (f == m) { ans = s; break; }
		q.push(make_pair(f - 1, s + 1));
		q.push(make_pair(f + 1, s + 1));
		q.push(make_pair(2 * f, s + 1));
	}

	return ans;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int ans = hide(n, m);
	cout << ans << endl;
	return 0;
}

//https://www.acmicpc.net/problem/1697

/*
Did I thought it can be solved by dynamic?
Unfortunately, it was bfs! da-da
*/