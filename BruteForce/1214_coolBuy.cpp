#include <iostream>
#include <algorithm>

using namespace std;

int D, P, Q, ans;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D >> P >> Q;
	if (P < Q) swap(P, Q);
	if (D % P == 0 || D % Q == 0)
	{
		cout << D << '\n';
		return 0;
	}
	ans = (D / P) * P + P;
	int tmp = ans;
	for (int i = 1; i <= tmp / P; i++)
	{
		int now = tmp - P * i;
		if ((D - now) % Q == 0)
		{
			cout << D << '\n';
			return 0;
		}
		now += ((D - now) / Q) * Q + Q;
		if (ans == now) break;
		ans = min(ans, now);
	}
	cout << ans << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/1214