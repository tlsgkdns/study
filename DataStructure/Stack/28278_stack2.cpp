#include <iostream>

using namespace std;
int S[1000001], N, C, X, idx = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C;
		if (C == 1)
		{
			cin >> X;
			S[idx++] = X;
		}
		if (C == 2)
		{
			if (idx == 0) cout << -1 << '\n';
			else cout << S[--idx] << '\n';
		}
		if (C == 3)
		{
			cout << idx << '\n';
		}
		if (C == 4)
		{
			cout << (idx == 0) << '\n';
		}
		if (C == 5)
		{
			if (idx == 0) cout << -1 << '\n';
			else cout << S[idx - 1] << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/28278