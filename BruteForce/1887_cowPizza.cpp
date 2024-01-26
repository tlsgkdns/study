#include <iostream>

using namespace std;
int T, N, C[52], Z, P;
int solve(int idx, int pizza)
{
	if (idx == T)
	{
		for (int i = 0; i < N; i++)
			if ((pizza | C[i]) == pizza)
				return 0;
		return 1;
	}
	return solve(idx + 1, pizza | (1 << idx)) + solve(idx + 1, pizza);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Z;
		while (Z--)
		{
			cin >> P;
			C[i] |= (1 << (P - 1));
		}
	}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1887