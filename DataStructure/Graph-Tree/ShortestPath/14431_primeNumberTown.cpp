#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
const int MAX = 9000001;
const int INF = 1000000007;
vector<pii> P, adj[4003];
int X1, Y1, X2, Y2, N, X, Y, ans = -1;
bool isPrime[MAX];
int D[4003];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	cin >> X1 >> Y1 >> X2 >> Y2;
	P.push_back({ X1, Y1 });
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		P.push_back({ X, Y });
	}
	P.push_back({ X2, Y2 });
	for (int n = 2; n * n < MAX; n++)
	{
		if (!isPrime[n]) continue;
		for (int i = n + n; i < MAX; i += n)
			isPrime[i] = false;
	}
	for (int i = 0; i <= N + 1; i++)
	{
		D[i] = INF;
		for (int j = 1; j <= N + 1; j++)
		{
			int dist = sqrt(pow(P[i].first - P[j].first, 2) + pow(P[i].second - P[j].second, 2));
			if (isPrime[dist])
			{
				adj[i].push_back({ dist, j });
				adj[j].push_back({ dist, i });
			}
		}
	}
	priority_queue<pair<int, int>> pq;
	D[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (here == N + 1)
		{
			ans = D[here];
			break;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int nxtCost = adj[here][i].first + cost;
			int there = adj[here][i].second;
			if (D[there] <= nxtCost) continue;
			D[there] = nxtCost;
			pq.push({ -nxtCost, there });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14431