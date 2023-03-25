#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int T, K;
priority_queue<ll> pq;
ll N, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> N;
			pq.push(-N);
		}
		while (pq.size() > 1)
		{
			ll s1 = -pq.top();
			pq.pop();
			ll s2 = -pq.top();
			pq.pop();
			ll s = s1 + s2;
			ans += s;
			pq.push(-s);
		}
		pq.pop();
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/13975