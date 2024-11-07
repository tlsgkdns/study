#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 250001;
vector<int> adj[MAX];
ll N, Q, K, A, B, S[MAX], P[MAX];
ll cnt[MAX], parent[MAX];
bool v[MAX], v2[MAX];

void dfs(int here, int p)
{
	parent[here] = p;
	for (int there : adj[here])
	{
		if (p == there) continue;
		dfs(there, here);
	}
}
int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a > b) swap(a, b);
	P[b] = a;
	cnt[a] += cnt[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	dfs(1, 0);
	cin >> Q;
	while (Q--)
	{
		ll ans = 0;
		cin >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> S[i];
			v[S[i]] = true;
			P[S[i]] = S[i];
			cnt[S[i]] = 1;
		}
		for (int i = 0; i < K; i++)
			if (v[parent[S[i]]])
				merge(S[i], parent[S[i]]);
		for (int i = 0; i < K; i++)
		{
			int idx = find(S[i]);
			if (!v2[idx])
			{
				v2[idx] = true;
				ans += (cnt[idx] * (cnt[idx] - 1)) / 2;
			}
		}

		for (int i = 0; i < K; i++)
		{
			v[S[i]] = false;
			P[S[i]] = S[i];
			cnt[S[i]] = 0;
			v2[S[i]] = false;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/25402