#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
vector<pair<ll, ll>> arr;
ll K, N, A[300001], cnt[300001];
ll s = 0, ans = 0, c = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		s += A[i];
		arr.push_back({ -s, i });
	}
	c = K;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < K; i++)
		cnt[arr[i].second] = -1;
	for (int i = 0; i < N; i++)
	{
		ans += A[i] * c;
		c += cnt[i];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/29767