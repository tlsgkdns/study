#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K, ans = -1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	int tmp = N;
	for (int n = K; n >= 1; n--)
	{
		tmp -= n;
		if (tmp < 0)
			break;
	}
	if (tmp >= 0)
	{
		tmp %= K;
		if (tmp == 0) ans = K - 1;
		else ans = K;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/19939