#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const ll INF = 1e9;

int N, M;
ll E[1001][1001], D[1001], ans1 = 0, ans2 = 0;
bool S[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
		D[i] = INF * INF;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> E[i][j];
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 0 });
	D[0] = 0;
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (now == M)
		{
			ans1 = D[now] / INF;
			ans2 = D[now] % INF;
		}
		for (int nxt = 0; nxt < N; nxt++)
		{
			if (E[now][nxt] == 0) continue;
			ll nxtCost = ((S[nxt] != S[now]) ? INF : 0) + E[now][nxt] + cost;
			if (nxtCost >= D[nxt]) continue;
			D[nxt] = nxtCost;
			pq.push({ -nxtCost, nxt });
		}
	}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/17940