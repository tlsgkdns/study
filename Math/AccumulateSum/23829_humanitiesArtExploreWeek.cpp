#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll N, Q, P[100001], X;
ll A[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> P[i];
	sort(P, P + N);
	for (int i = 0; i < N; i++)
	{
		if (i == 0) A[i] = P[i];
		else A[i] = A[i - 1] + P[i];
	}
	while (Q--)
	{
		cin >> X;

		ll ans = 0, lcnt = (lower_bound(P, P + N, X) - P), rcnt = N - (upper_bound(P, P + N, X) - P);
		if (lcnt > 0) ans += (lcnt * X) - A[lcnt - 1];
		if (rcnt > 0) ans += ((A[N - 1] - ((N - rcnt - 1 < 0) ? 0 : (A[N - rcnt - 1]))) - (X * rcnt));
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/23829