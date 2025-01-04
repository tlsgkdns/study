#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> x, y, arr;
int N, X[41], Y[41], C[41], ans = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i] >> C[i];
		x.push_back(X[i]); y.push_back(Y[i]);
	}
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	for (int xidx1 = 0; xidx1 < N; xidx1++)
		for (int xidx2 = xidx1; xidx2 < N; xidx2++)
			for (int yidx1 = 0; yidx1 < N; yidx1++)
				for (int yidx2 = yidx1; yidx2 < N; yidx2++)
				{
					int cnt = 0, s = 0, r = 2 * (x[xidx2] - x[xidx1]) + 2 * (y[yidx2] - y[yidx1]);
					for (int idx = 0; idx < N; idx++)
						if (x[xidx1] <= X[idx] && X[idx] <= x[xidx2] && y[yidx1] <= Y[idx] && Y[idx] <= y[yidx2])
						{
							arr.push_back(C[idx]);
						}
						else
						{
							++cnt;
							s += C[idx];
						}
					sort(arr.begin(), arr.end());
					for (int i = arr.size() - 1; i >= 0 && s < r; i--, cnt++)
					{
						s += arr[i];
					}
					if (s >= r)
					{
						ans = min(ans, cnt);
					}
					arr.clear();
				}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1047