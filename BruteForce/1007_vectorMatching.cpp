#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
pair<int, int> P[21];
bool v[21];
int T, N;
double ans = 20000000000007;
void solve(int idx, int d)
{
	if (d == N)
	{
		int y = 0, x = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i])
			{
				y += P[i].first;
				x += P[i].second;
			}
			else
			{
				y -= P[i].first;
				x -= P[i].second;
			}
		}
		ans = min(ans, sqrt(pow(y, 2) + pow(x, 2)));
	}
	for (int i = idx; i < N; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		solve(i + 1, d + 2);
		v[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed;  cout.precision(9);
	cin >> T;
	while (T--)
	{
		ans = 20000000000007;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
		solve(0, 0);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1007