#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, K, S, P, C, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<int, int>> pq1, pq2;
	cin >> N >> K >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> C;
		if (S > P) pq1.push({ S - P, C });
		else pq2.push({ P - S, C });
	}
	while (!pq1.empty() || !pq2.empty())
	{
		int d1 = (pq1.empty()) ? 0 : pq1.top().first;
		int d2 = (pq2.empty()) ? 0 : pq2.top().first;
		priority_queue<pair<int, int>>& q = (d1 > d2) ? pq1 : pq2;
		ans += (d1 > d2) ? d1 * 2 : d2 * 2;
		int cap = 0;
		while (!q.empty() && cap < K)
		{
			int d = q.top().first;
			int s = q.top().second;
			q.pop();
			if (cap + s <= K)
				cap += s;
			else
			{
				q.push({ d, (cap + s) - K });
				cap = K;
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2513