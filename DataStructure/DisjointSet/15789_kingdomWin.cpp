#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001], kingdom;
int N, M, X, Y, C, H, K, P[100001], cnt[100001], ans = 0;
bool v[100001];
int find(int p)
{
	if (p == P[p]) return p;
	return P[p] = find(P[p]);
}
void merge(int p, int q)
{
	p = find(p); q = find(q);
	if (p < q) swap(p, q);
	if (p == q) return;
	P[p] = q;
	cnt[q] += cnt[p];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		P[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		merge(X, Y);
	}
	cin >> C >> H >> K;
	ans = cnt[find(C)]; v[find(C)] = true; v[find(H)] = true;
	for (int i = 1; i <= N; i++)
	{
		if (v[find(i)]) continue;
		v[find(i)] = true;
		kingdom.push_back(-cnt[i]);
	}
	sort(kingdom.begin(), kingdom.end());
	for (int i = 0; i < min((int)kingdom.size(), K); ++i) ans -= kingdom[i];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15789