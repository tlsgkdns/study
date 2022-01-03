#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;

const int INF = 1000000001;
int N, st = -1;
vector<int> cows;
ll ans = INF;
ll GetEnerge(int s, int e)
{
	if (e < s) return pow(N - s + e, 2);
	return pow(e - s, 2);
}
int getNextPos(int pos)
{
	return (pos + 1) % N;
}
ll solve(int s)
{
	vector<bool> barn(N, false), noLine(N, false);
	ll ret = 0;
	queue<int> q;
	int tmp = st;
	while (tmp != s)
	{
		for (int i = 0; i < cows[tmp]; i++)
			q.push(tmp);
		noLine[tmp] = true;
		tmp = getNextPos(tmp);
	}
	int cnt = 0, pos = s;
	while (cnt < N)
	{
		if (!noLine[pos])
			for (int j = 0; j < cows[pos]; j++)
				q.push(pos);
		if (barn[pos])
		{
			pos = getNextPos(pos);
			continue;
		}
		noLine[pos] = true;
		if (q.empty())
		{
			pos = getNextPos(pos);
			continue;
		}
		cnt++; barn[pos] = true;
		ret += GetEnerge(q.front(), pos);
		q.pop();
		pos = getNextPos(pos);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; cows.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> cows[i];
		if (cows[i] != 0 && st == -1) st = cows[i];
	}
	for (int i = 0; i < N; i++)
		ans = min(ans, solve(i));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11996