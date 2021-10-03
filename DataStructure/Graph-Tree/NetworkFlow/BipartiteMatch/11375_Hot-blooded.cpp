#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector<bool> v;
vector<int> cnt;
vector<list<int>> can;

bool dfs(int x)
{
	if (v[x]) return false;
	v[x] = true;

	for (int e : can[x])
	{
		if (cnt[e] == -1 || dfs(cnt[e]))
		{
			cnt[e] = x;
			return true;
		}
	}

	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	can.resize(n);
	cnt.resize(m, -1);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int tmp;
			cin >> tmp;
			can[i].push_back(tmp - 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		v.clear();
		v.resize(m, false);
		ans += dfs(i);
	}

	cout << ans << endl;
}

// https://www.acmicpc.net/problem/11375