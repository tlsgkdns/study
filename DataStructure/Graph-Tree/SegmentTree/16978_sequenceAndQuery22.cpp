#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 100001;
ll A[MAX], T[MAX * 4], ans[MAX];
int N, M, q, a, b, c, cnt = 0;
vector<pair<int, int>> S;
vector<pair<int, pair<int, int>>> Q[MAX];
ll init(int s, int e, int node)
{
	if (s == e) return T[node] = A[s];
	int m = (s + e) / 2;
	return T[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}
ll get(int l, int r, int nl, int nr, int node)
{
	if (r < nl || nr < l) return 0;
	if (l <= nl && nr <= r) return T[node];
	int m = (nl + nr) / 2;
	return get(l, r, nl, m, node * 2) + get(l, r, m + 1, nr, node * 2 + 1);
}
void update(int l, int r, int idx, int node, int d)
{
	if (idx < l || r < idx) return;
	T[node] += d;
	if (l == r) return;
	int m = (l + r) / 2;
	update(l, m, idx, node * 2, d);
	update(m + 1, r, idx, node * 2 + 1, d);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> a >> b;
			S.push_back({ a, b });
		}
		else
		{
			cin >> a >> b >> c;
			Q[a].push_back({ cnt++, {b, c} });
		}
	}
	init(1, N, 1);
	for (int i = 0; i < S.size() + 1; i++)
	{
		for (int j = 0; j < Q[i].size(); j++)
			ans[Q[i][j].first] = get(Q[i][j].second.first, Q[i][j].second.second, 1, N, 1);
		if (i == S.size()) break;
		update(1, N, S[i].first, 1, S[i].second - A[S[i].first]);
		A[S[i].first] = S[i].second;
	}
	for (int i = 0; i < cnt; i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/16978