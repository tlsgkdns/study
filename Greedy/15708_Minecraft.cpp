#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int N, T, P, K[100001], t = 0, ans = 0;
long long S = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T >> P;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) cin >> K[i];
	for (int i = 0; i < N; i++)
	{
		S += K[i] + ((i == 0) ? 0 : P);
		pq.push(K[i]);
		while (!pq.empty() && S > T)
		{
			S -= pq.top();
			pq.pop();
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15708