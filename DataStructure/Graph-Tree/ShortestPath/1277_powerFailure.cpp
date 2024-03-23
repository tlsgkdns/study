#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector<pair<int, double>> adj[1001];
int N, W, X[1001], Y[1001], A, B;
bool v[1001][1001];
double M, D[1001];
double getDist(int idx1, int idx2)
{
	return sqrt(pow(X[idx1] - X[idx2], 2) + pow(Y[idx1] - Y[idx2], 2));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> W;
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> Y[i] >> X[i];
		D[i] = 1000000007;
	}
	for (int i = 0; i < W; i++)
	{
		cin >> A >> B;
		v[A][B] = true;
		v[B][A] = true;
	}
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
		{
			double d = getDist(i, j);
			if (v[i][j] || d <= M)
			{
				adj[i].push_back({ j, (v[i][j]) ? 0 : d });
				adj[j].push_back({ i, (v[i][j]) ? 0 : d });
			}
		}
	priority_queue<pair<double, int>> pq;
	D[1] = 0;
	pq.push({ 0.0, 1 });
	while (!pq.empty())
	{
		double cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (D[now] < cost) continue;
		for (int i = 0; i < adj[now].size(); i++)
		{
			int nxt = adj[now][i].first;
			double nxtCost = cost + adj[now][i].second;
			if (D[nxt] > nxtCost)
			{
				D[nxt] = nxtCost;
				pq.push({ -nxtCost, nxt });
			}
		}
	}
	int ans = D[N] * 1000;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1277