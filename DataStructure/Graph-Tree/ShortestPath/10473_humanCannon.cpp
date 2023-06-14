#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const double INF = 1000000007;
const int MAX = 103;
double sy, sx, ey, ex, Y[MAX], X[MAX], D[MAX], ans = INF;
double adj[MAX][MAX];
int N;

double getCost(int here, int there)
{
	return sqrt(pow(Y[here] - Y[there], 2) + pow(X[here] - X[there], 2));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> sy >> sx >> ey >> ex;
	cin >> N;
	Y[0] = sy; X[0] = sx;
	Y[N + 1] = ey; X[N + 1] = ex;
	for (int i = 1; i <= N; i++)
	{
		cin >> Y[i] >> X[i];
		D[i] = INF;
	}
	D[0] = 0; D[N + 1] = INF;
	for (int i = 0; i <= N + 1; i++)
		for (int j = i + 1; j <= N + 1; j++)
		{
			adj[i][j] = getCost(i, j);
			adj[j][i] = adj[i][j];
		}
	priority_queue<pair<double, int>> pq;
	pq.push({ 0, 0 });
	adj;
	while (!pq.empty())
	{
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (D[here] < cost) continue;
		if (here == N + 1)
		{
			ans = D[here];
			break;
		}
		if (here == 0)
		{
			for (int there = 1; there <= N + 1; there++)
			{
				double d = adj[here][there] / 5;
				D[there] = d;
				pq.push({ -d, there });
			}
		}
		else
		{
			for (int there = 1; there <= N + 1; there++)
			{
				double d = min(adj[here][there] / 5, (abs(adj[here][there] - 50)) / 5 + 2), nxt = cost + d;
				if (nxt >= D[there]) continue;
				D[there] = nxt;
				pq.push({ -nxt, there });
			}

		}
	}
	cout << fixed; cout.precision(6);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10473