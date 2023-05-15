#include <iostream>
#include <vector>
using namespace std;

int N, Q, X, A, C, D, P[200001], p;
vector<int> tmp;
vector<bool> ans;
vector<pair<int, pair<int, int>>> q;
int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a > b) swap(a, b);
	P[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) P[i] = i;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p;
		tmp.push_back(p);
	}
	for (int i = 0; i < N - 1 + Q; i++)
	{
		cin >> X;
		if (X == 0)
		{
			cin >> A;
			q.push_back({ X, {A, 0} });
		}
		else
		{
			cin >> C >> D;
			q.push_back({ X, {C, D} });
		}
	}
	for (int i = q.size() - 1; i >= 0; i--)
	{
		int typ = q[i].first;
		int p1 = q[i].second.first;
		int p2 = q[i].second.second;
		if (typ == 1) ans.push_back(find(p1) == find(p2));
		else merge(tmp[p1 - 2], p1);
	}
	for (int i = Q - 1; i >= 0; i--)
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
}

// https://www.acmicpc.net/problem/13306