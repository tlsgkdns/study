#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int MAX = 100001;
const ll INF = 10000000001;
vector<pii> X[MAX], Y[MAX];
vector<ll> dist(2 * MAX, INF);
int M, N, K, A, B;
ll ans = -1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> K;
	X[M].push_back({ N, K });
	Y[N].push_back({ M, K });
	for (int i = 0; i < K; i++)
	{
		cin >> A >> B;
		X[A].push_back({ B, i });
		Y[B].push_back({ A, i });
	}
	priority_queue<pair<pair<ll, pair<int, pii>>, bool>> pq;
	pq.push({ {0, {-1, {1, 1}}}, false });
	while (!pq.empty())
	{
		ll cost = -pq.top().first.first;
		int num = pq.top().first.second.first;
		int y = pq.top().first.second.second.first;
		int x = pq.top().first.second.second.second;
		bool vert = pq.top().second;
		pq.pop();
		if (num > 0 && dist[num] < cost) continue;
		if (y == N && x == M)
		{
			ans = dist[K];
			break;
		}
		if (vert)
		{
			for (int i = 0; i < Y[y].size(); i++)
			{
				ll nxtCost = cost + abs(Y[y][i].first - x) + 1;
				if (dist[Y[y][i].second] > nxtCost)
				{
					dist[Y[y][i].second] = nxtCost;
					pq.push({ {-nxtCost, { Y[y][i].second, {y, Y[y][i].first}}}, false });
				}
			}
		}
		else
		{
			for (int i = 0; i < X[x].size(); i++)
			{
				ll nxtCost = cost + abs(X[x][i].first - y) + 1;
				if (dist[X[x][i].second] > nxtCost)
				{
					dist[X[x][i].second] = nxtCost;
					pq.push({ {-nxtCost, {X[x][i].second, {X[x][i].first, x}}}, true });
				}
			}
		}
	}
	if (ans > 0) ans--;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5529