#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, s, sum = 0, ans = 100001;
	cin >> n >> s;
	vector<ll> arr(n);
	queue<ll> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		q.push(arr[i]);
		sum += arr[i];
		ll tmp = 0;
		while (!q.empty())
		{
			if (sum == s) break;
			if (sum - q.front() < s) break;
			sum -= q.front();
			q.pop();
		}
		ll qs = q.size();
		if (sum >= s) ans = min(ans, qs);
	}
	if (ans == 100001) cout << 0 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1806
