#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
using ll = long long;
ll N, K, cnt = 0, A, ans = 0;
unordered_map<ll, ll> um;
queue<ll> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		um.insert({ A, 0 });
		q.push(A);
	}
	while (cnt < K)
	{
		int here = q.front(), d = um[here];
		q.pop();
		if (cnt < K && um.count(here + 1) == 0)
		{
			q.push(here + 1);
			um[here + 1] = d + 1;
			ans += d + 1;
			++cnt;
		}
		if (cnt < K && um.count(here - 1) == 0)
		{
			q.push(here - 1);
			um[here - 1] = d + 1;
			ans += d + 1;
			++cnt;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18513