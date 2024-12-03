#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int N, Q, cnt[1000001][32], S, E;
ll A, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		int idx = 0;
		while (A > 1)
		{
			cnt[i][idx++] = (A % 2);
			A /= 2;
		}
		cnt[i][idx] = A;
	}
	for (int i = 0; i < 32; i++)
		for (int j = 1; j <= N; j++)
			cnt[j][i] += cnt[j - 1][i];
	while (Q--)
	{
		cin >> S >> E;
		ll b = 1, n = 0;
		for (int i = 0; i < 32; i++, b *= 2)
			n += (b * ((cnt[E][i] - cnt[S - 1][i]) % 2));
		ans ^= n;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16713