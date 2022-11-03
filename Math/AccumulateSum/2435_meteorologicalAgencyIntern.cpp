#include <iostream>
#include <algorithm>
using namespace std;

int num, ps[101], N, K, ans = -10000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K; ps[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		ps[i] = ps[i - 1] + num;
	}
	for (int i = K; i <= N; i++)
		for (int idx = 1; idx < N - i + 2; idx++)
			ans = max(ps[idx + K - 1] - ps[idx - 1], ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2435