#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
int course[501][501], parent[250001], rk[250001];
int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };
vector<pair<int, pii>> edges;
vector<int> qry, idxToVal, ans;
vector<pii> range;
unordered_map<int, int> valToIdx;
int M, N, T, df, Q = 0;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < M && x < N;
}
int getNum(int y, int x)
{
	return (y * N) + x;
}
void init()
{
	for (int i = 0; i < (N * M); i++)
	{
		parent[i] = i;
		rk[i] = 1;
	}
}
int find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	if (rk[u] > rk[v]) swap(u, v);
	parent[u] = v;
	int tmp = rk[v];
	rk[v] += rk[u];
	rk[u] += tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> T;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> course[i][j];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> df;
			if (df == 1) qry.push_back(getNum(i, j));
		}
	Q = qry.size();
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int now = getNum(i, j);
			for (int d = 0; d < 2; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (!inRange(ny, nx)) continue;
				int rat = abs(course[i][j] - course[ny][nx]);
				edges.push_back(make_pair(rat, make_pair(now, getNum(ny, nx))));
				if (valToIdx.count(rat) == 0)
				{
					valToIdx[rat] = -1;
					idxToVal.push_back(rat);
				}
			}
		}
	int mx = idxToVal.size();
	sort(idxToVal.begin(), idxToVal.end()); sort(edges.begin(), edges.end());
	ans.resize(Q);
	for (int i = 0; i < mx; i++) valToIdx[idxToVal[i]] = i;
	for (int i = 0; i < Q; i++) range.push_back({ 0, mx });
	vector<vector<int>> mids(mx + 1);
	while (true)
	{
		for (int i = 0; i <= mx; i++) mids[i].clear();
		bool chk = false;
		for (int i = 0; i < Q; i++)
		{
			if (range[i].first + 1 < range[i].second)
			{
				chk = true;
				mids[((range[i].first + range[i].second) / 2)].push_back(i);
			}
		}
		if (!chk) break;
		init();
		for (int i = 0; i < edges.size(); i++)
		{
			int u, v, c;
			c = edges[i].first;
			u = edges[i].second.first;
			v = edges[i].second.second;
			merge(u, v);
			if (i + 1 == edges.size() || edges[i + 1].first != c)
			{
				for (int j : mids[valToIdx[c]])
				{
					parent; int sz = rk[find(qry[j])];
					if (sz >= T)
					{
						range[j].second = valToIdx[c];
						ans[j] = c;
					}
					else
						range[j].first = valToIdx[c];
				}
			}
		}

	}
	ll s = 0;
	for (ll a : ans) s += a;
	cout << s << '\n';
}

// https://www.acmicpc.net/problem/9877