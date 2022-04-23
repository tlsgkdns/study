#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> order;
int N, K, id, W;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<int, pair<int, int>>> pq;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> id >> W;
		if (i < K) pq.push({ -W, {-i, id} });
		else
		{
			int T = pq.top().first;
			int R = pq.top().second.first;
			int ID = pq.top().second.second;
			pq.pop();
			order.push_back({ -T, {R, ID} });
			pq.push({ T - W, {R, id} });
		}
	}
	while (!pq.empty())
	{
		pair<int, pair<int, int>> p = pq.top();
		p.first = -p.first;
		order.push_back(p);
		pq.pop();
	}
	sort(order.begin(), order.end());
	long long ans = 0;
	for (int i = 0; i < N; i++)
		ans += ((long long)order[i].second.second * (i + 1));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17612