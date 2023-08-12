#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
queue<pair<int, int>> P, M;
ll L, N, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L;
		if (L == 0) continue;
		if (L > 0) P.push({ i, L });
		else M.push({ i, -L });
	}
	while (!P.empty() && !M.empty())
	{
		int p = P.front().second;
		int m = M.front().second;
		int c = abs(P.front().first - M.front().first);
		if (p == m)
		{
			P.pop();
			M.pop();
		}
		else if (p < m)
		{
			P.pop();
			M.front().second -= p;
		}
		else
		{
			M.pop();
			P.front().second -= m;
		}
		ans += min(p, m) * c;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14943