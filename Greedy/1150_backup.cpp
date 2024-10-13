#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
const ll MAX = 100000000000000000;
ll ans = 0;
priority_queue<pair<ll, int>> pq;
ll S[100002], N, K, D[100002], cnt = 0, L[100002], R[100002];
bool v[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		L[i] = i - 1;
		R[i] = i + 1;
		if (i > 1)
		{
			D[i] = S[i] - S[i - 1];
			pq.push({ -D[i], i });
		}
	}
	L[N + 1] = N;
	D[1] = D[N + 1] = MAX;
	pq.push({ -D[1], 1 });
	pq.push({ -D[N + 1], N + 1 });
	while (cnt < K)
	{
		ll cost = -pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if (v[idx]) continue;
		++cnt;
		ans += cost;
		D[idx] = D[R[idx]] + D[L[idx]] - D[idx];
		pq.push({ -D[idx], idx });
		v[L[idx]] = true;
		v[R[idx]] = true;
		R[idx] = R[R[idx]];
		L[idx] = L[L[idx]];
		R[L[idx]] = L[R[idx]] = idx;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1150