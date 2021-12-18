#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int N, M, A, B, C, ans = 0;
vector<int> lounge1, lounge2;
vector<vector<int>> adj;
vector<pair<int, int>> input;
vector<bool> v;
int dfs1(int here, int clr)
{
	int ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (lounge1[there] == clr) continue;
		if (lounge1[there] == !clr) return -1;
		v[there] = true;
		if (clr) ret++;
		lounge1[there] = clr;
		int d = dfs1(there, !clr);
		if (d == -1)
		{
			return -1;
		}
		ret += d;
	}
	return ret;
}
int dfs2(int here, int clr)
{
	int ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (lounge2[there] == clr) continue;
		if (lounge2[there] == !clr) return -1;
		v[there] = true;
		if (clr) ret++;
		lounge2[there] = clr;
		int d = dfs2(there, !clr);
		if (d == -1)
		{
			return -1;
		}
		ret += d;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	lounge1.resize(N + 1, -1); adj.resize(N + 1);
	v.resize(N + 1, false);
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		if (ans == -1) continue;
		if (C == 0)
		{
			if (lounge1[A] == 1 || lounge1[B] == 1)
				ans = -1;
			else if (ans != -1)
			{
				lounge1[A] = 0;
				lounge1[B] = 0;
			}
		}
		if (C == 2)
		{
			if (lounge1[A] == 0 || lounge1[B] == 0)
				ans = -1;
			else if (ans != -1)
			{
				if (lounge1[A] == -1) ans++;
				if (lounge1[B] == -1) ans++;
				lounge1[A] = 1;
				lounge1[B] = 1;
			}
		}
		if (C == 1)
		{
			if ((lounge1[A] == 1 && lounge1[B] == 1) || (lounge1[A] == 0 && lounge1[B] == 0))
			{
				ans = -1;
			}
			else
			{
				adj[A].push_back(B);
				adj[B].push_back(A);
				input.push_back({ A, B });
			}
		}
	}
	for (int i = 0; i < input.size(); i++)
	{
		A = input[i].first;
		B = input[i].second;
		if ((lounge1[A] == 1 && lounge1[B] == 1) || (lounge1[A] == 0 && lounge1[B] == 0))
		{
			ans = -1;
			break;
		}
	}
	lounge2 = lounge1;
	for (int i = 1; i <= N; i++)
	{
		if (ans == -1) break;
		if (v[i]) continue;
		if (lounge1[i] == -1)
		{
			v[i] = true;
			lounge1[i] = 1;
			int a = dfs1(i, 0);
			if (a != -1) a++;
			lounge2[i] = 0;
			int b = dfs2(i, 1);
			if (a == -1 && b == -1) ans = -1;
			else
			{
				if (a == -1) a = INF;
				if (b == -1) b = INF;
				ans += min(a, b);
			}
		}
	}
	if (ans == -1) cout << "impossible\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10259