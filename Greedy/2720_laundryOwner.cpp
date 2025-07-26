#include <iostream>
#include <cstring>
using namespace std;
int ans[4], N, T, C, M[4] = { 25, 10, 5, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(ans, 0, sizeof(ans));
		cin >> C;
		for (int idx = 0; idx < 4; idx++)
		{
			while (M[idx] <= C)
			{
				ans[idx]++;
				C -= M[idx];
			}
		}
		for (int i = 0; i < 4; i++) cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2720