#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> ans;
int N, M, T, K, m = 0;
bool v1[1000001], v2[1000001];
int X[101], Y[101];
vector<int> x, y;
vector<pair<int, int>> P;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T >> K;
	for (int i = 0; i < T; i++)
	{
		cin >> X[i] >> Y[i];
		if (!v1[X[i]])
		{
			v1[X[i]] = true;
			x.push_back(X[i]);
		}
		if (!v2[Y[i]])
		{
			v2[Y[i]] = true;
			y.push_back(Y[i]);
		}
	}
	for (int i = 0; i < x.size(); i++)
		for (int j = 0; j < y.size(); j++)
		{
			int sx = x[i], sy = y[j], ex = sx + K, ey = sy + K, cnt = 0;
			for (int idx = 0; idx < T; idx++)
				if (X[idx] >= sx && X[idx] <= ex && Y[idx] >= sy && Y[idx] <= ey)
					++cnt;
			if (cnt > m)
			{
				ans = { x[i], y[j] + K };
				m = cnt;
			}
		}
	if (ans.first + K > N) ans.first = N - K;
	if (ans.second > M) ans.second = M;
	cout << ans.first << " " << ans.second << '\n' << m << '\n';
}
// https://www.acmicpc.net/problem/2492