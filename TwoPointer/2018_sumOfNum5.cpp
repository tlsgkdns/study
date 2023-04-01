#include <iostream>

using namespace std;

int N, ans = 0, s = 1, idx1 = 1, idx2 = 2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (idx2 <= N + 1)
	{
		if (s == N) ++ans;
		if (s > N)
			s -= idx1++;
		else
			s += idx2++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2018