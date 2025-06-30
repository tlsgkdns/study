#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C, M, F = 0, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> M;
	for (int i = 0; i < 24; i++)
	{
		if (F + A > M)
		{
			F = max(0, F - C);
		}
		else
		{
			F += A;
			ans += B;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22864