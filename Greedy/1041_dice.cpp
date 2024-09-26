#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const ll MAX = 1000000000000000000;
ll N;
ll ans = MAX, one = MAX, two = MAX, three = MAX, D[6], ecnt = 0, mcnt = 0;
int V[8][3] = { {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5} };
int E[12][2] = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {1, 5}, {2, 5}, {3, 5}, {4, 5} };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 6; i++)
	{
		cin >> D[i];
		one = min(one, D[i]);
	}
	if (N == 1)
	{
		ans = 0; ll mx = 0;
		for (int i = 0; i < 6; i++)
		{
			ans += D[i];
			mx = max(mx, D[i]);
		}
		ans -= mx;
		cout << ans << '\n';
		return 0;
	}
	mcnt = 5 * ((N - 2) * (N - 2)) + 4 * (N - 2);
	ecnt = ((5 * N * N) - mcnt - 12) / 2;
	for (int i = 0; i < 8; i++)
		three = min(three, D[V[i][0]] + D[V[i][1]] + D[V[i][2]]);
	for (int i = 0; i < 12; i++)
		two = min(two, D[E[i][0]] + D[E[i][1]]);
	cout << three * 4 + two * ecnt + one * mcnt << '\n';
}

// https://www.acmicpc.net/problem/1041