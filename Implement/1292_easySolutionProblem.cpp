#include <iostream>

using namespace std;

int idx = 0, A, B, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B; --A; --B;
	int cnt = 0, num = 1;
	for (int i = 0; i <= B; i++)
	{
		if (i >= A) ans += num;
		if (++cnt == num)
		{
			cnt = 0;
			++num;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1292