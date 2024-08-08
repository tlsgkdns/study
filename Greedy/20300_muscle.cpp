#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll N, T[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	int l = 0, r = (N % 2 > 0) ? N - 2 : N - 1;
	ll ans = (N % 2 > 0) ? T[N - 1] : 0;
	while (l < r) ans = max(ans, T[l++] + T[r--]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20300