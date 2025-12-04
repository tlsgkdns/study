#include <iostream>

using namespace std;
long long N;
bool cnt[32];
string ans = "NO\n";
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	while (N > 0)
	{
		long long n = 1;
		int i = 0;
		for (; n <= N; n *= 3, i++);
		n /= 3;
		ans = "YES\n";
		if (cnt[i])
		{
			ans = "NO\n";
			break;
		}
		cnt[i] = true;
		N -= n;
	}
	cout << ans;
}

// https://www.acmicpc.net/problem/17252