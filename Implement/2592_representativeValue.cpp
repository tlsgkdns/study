#include <iostream>

using namespace std;

int N, ans = 0, cnt[1001], ans2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
	{
		cin >> N;
		ans += N;
		cnt[N]++;
	}
	ans /= 10;
	for (int i = 0; i <= 1000; i++)
		if (cnt[i] > cnt[ans2])
			ans2 = i;
	cout << ans << '\n' << ans2 << '\n';
}

// https://www.acmicpc.net/problem/2592