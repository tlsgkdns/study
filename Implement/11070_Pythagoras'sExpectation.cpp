#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, M, A, B, P, Q;
double L[1001], W[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(L, 0, sizeof(L));
		memset(W, 0, sizeof(W));
		cin >> N >> M;
		int ans1 = 0, ans2 = 1000000000;
		for (int i = 0; i < M; i++)
		{
			cin >> A >> B >> P >> Q;
			L[A] += Q; L[B] += P;
			W[A] += P; W[B] += Q;
		}
		for (int i = 1; i <= N; i++)
		{
			double a = 0;
			if (L[i] != 0 || W[i] != 0)
				a = (W[i] * W[i]) / (L[i] * L[i] + W[i] * W[i]);
			a *= 1000;
			ans1 = max((int)a, ans1);
			ans2 = min((int)a, ans2);
		}
		cout << ans1 << '\n' << ans2 << '\n';
	}
}

// https://www.acmicpc.net/problem/11070