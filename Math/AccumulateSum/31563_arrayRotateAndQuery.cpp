#include <iostream>
using namespace std;

int N, Q, A[400002], k, a, b, c, s = 0;
long long S[400002];
int getIdx(int idx)
{
	int ret = idx + s;
	if (ret < 0) ret += 2 * N;
	ret %= 2 * N;
	if (ret == 0) ret = 2 * N;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		S[i] = A[i] + S[i - 1];
	}
	for (int i = N + 1; i <= 2 * N; i++)
	{
		A[i] = A[i - N];
		S[i] = A[i] + S[i - 1];
	}
	while (Q--)
	{
		cin >> c;
		if (c == 1)
		{
			cin >> k;
			s -= k;
			if (s < 0) s += N;

		}
		else if (c == 2)
		{
			cin >> k;
			s += k;
			s %= N;
		}
		else
		{
			cin >> a >> b;
			cout << S[getIdx(b)] - S[getIdx(a) - 1] << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/31563