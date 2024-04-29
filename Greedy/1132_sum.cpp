#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

bool f = false;
bool Z[10];
int N, sel = 0;
ll D[10], ans = 0, t = 1;
string E;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> E;
		Z[E[0] - 'A'] = true;
		t = 1;
		for (int idx = E.size() - 1; idx >= 0; idx--)
		{
			D[E[idx] - 'A'] += t;
			t *= 10;
		}
	}

	for (int i = 0; i < 10; i++)
		if (D[i] == 0)
			f = true;
	if (!f)
	{

		ll m = 10000000000000000;
		for (int i = 0; i < 10; i++)
		{
			if (!Z[i] && D[i] < m)
			{
				m = D[i];
				sel = i;
			}
		}
		D[sel] = 0L;
	}
	sort(D, D + 10, greater<ll>());
	for (int i = 0, j = 9; i < 10; i++, j--) ans += (D[i] * j);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1132