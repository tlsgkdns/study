#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int v[200001];
int N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i <= 200000; i++) v[i] = 1000000007;
	cin >> N >> K;
	v[N] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, N });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (v[here] < cost) continue;
		if (here == K) break;
		int there = here * 2;
		if (there <= 200000 && v[there] > cost)
		{
			v[there] = cost;
			pq.push({ -v[there], there });
		}
		there = here + 1;
		if (there <= 100000 && v[there] > cost + 1)
		{
			v[there] = cost + 1;
			pq.push({ -v[there], there });
		}
		there = here - 1;
		if (there >= 0 && v[there] > cost + 1)
		{
			v[there] = cost + 1;
			pq.push({ -v[there], there });
		}
	}
	cout << v[K] << '\n';
}

// https://www.acmicpc.net/problem/13549