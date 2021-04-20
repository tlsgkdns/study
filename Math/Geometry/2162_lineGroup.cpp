#include <iostream>
#include <vector>
using namespace std;
using p = pair<int, int>;

vector<int> parent, rk;

int ccw(p& p1, p& p2, p& p3)
{
	int op = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	op -= (p1.first * p3.second + p2.first * p1.second + p3.first * p2.second);

	if (op > 0) return 1;
	else if (op == 0) return 0;
	return -1;
}

bool isIntersect(p& p1, p& p2, p& p3, p& p4)
{
	int l12 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int l21 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (l12 == 0 && l21 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}
	return l12 <= 0 && l21 <= 0;
}

int find(int u)
{
	if (u == parent[u]) return u;

	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	if (rk[u] > rk[v]) swap(u, v);
	parent[u] = v;
	if (rk[u] == rk[v]) ++rk[v];
}
int main()
{
	int n;
	cin >> n;
	vector<pair<p, p>> lines(n);
	parent.resize(n);
	rk.resize(n, 1);
	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++)
	{
		cin >> lines[i].first.first >> lines[i].first.second
			>> lines[i].second.first >> lines[i].second.second;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			if (isIntersect(lines[i].first, lines[i].second,
				lines[j].first, lines[j].second))
			{
				merge(i, j);
			}
		}
	int big = 0, cnt = 0, gNum = 0;
	vector<int> checked(n, 0);
	for (int i = 0; i < n; i++)
	{
		int u = find(i);
		if (checked[u] == 0) cnt++;
		checked[u]++;
		if (big < checked[u])
			big = checked[u];
	}
	cout << cnt << '\n' << big << '\n';
}

// https://www.acmicpc.net/problem/2162