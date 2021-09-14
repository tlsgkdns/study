#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000000;
int N;
vector<vector<int>> A;
int getPopuSub(int x, int y, int d1, int d2)
{
	vector<vector<int>> area(N + 1, vector<int>(N + 1, 0));
	vector<int> row(N + 1, 0);
	int popu[5] = { 0, 0, 0, 0, 0 };
	for (int d = 0; d <= d1; d++)
	{
		if (area[x + d][y - d] == 0)
		{
			popu[4] += A[x + d][y - d];
			area[x + d][y - d] = 5;
			row[x + d]++;
		}
	}
	for (int d = 0; d <= d2; d++)
	{
		if (area[x + d1 + d][y - d1 + d] == 0)
		{
			popu[4] += A[x + d1 + d][y - d1 + d];
			area[x + d1 + d][y - d1 + d] = 5;
			row[x + d1 + d]++;
		}
	}
	for (int d = 0; d <= d2; d++)
	{
		if (area[x + d][y + d] == 0)
		{
			popu[4] += A[x + d][y + d];
			area[x + d][y + d] = 5;
			row[x + d]++;
		}
	}
	for (int d = 0; d <= d1; d++)
	{
		if (area[x + d2 + d][y + d2 - d] == 0)
		{
			popu[4] += A[x + d2 + d][y + d2 - d];
			area[x + d2 + d][y + d2 - d] = 5;
			row[x + d2 + d]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (row[i] <= 1) continue;
		bool inSide = false;
		for (int j = 1; j <= N; j++)
		{
			if (!inSide && area[i][j] == 5)
				inSide = true;
			else if (inSide && area[i][j] != 5)
			{
				area[i][j] = 5;
				popu[4] += A[i][j];
			}
			else if (inSide && area[i][j] == 5)
				inSide = false;
		}
	}
	int idx = 0;
	for (int c = 1; c <= N; c++)
		for (int r = 1; r <= N; r++)
		{
			if (area[r][c] != 0) continue;
			if (r >= 1 && r < x + d1 && c >= 1 && c <= y) idx = 0;
			else if (r >= 1 && r <= x + d2 && c > y&& c <= N) idx = 1;
			else if (x + d1 <= r && r <= N && c >= 1 && c < y - d1 + d2) idx = 2;
			else if (x + d2 < r && r <= N && c >= y - d1 + d2 && c <= N) idx = 3;
			area[r][c] = idx + 1;
			popu[idx] += A[r][c];
		}
	int mn = INF, mx = -1;
	for (int i = 0; i < 5; i++)
	{
		mn = min(mn, popu[i]);
		mx = max(mx, popu[i]);
	}
	return (mx - mn);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int ans = INF;
	cin >> N;
	A.resize(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	for (int d1 = 1; d1 < N - 1; d1++)
		for (int d2 = 1; d2 < N - 1; d2++)
			for (int y = d1 + 1; y <= N - d2; y++)
				for (int x = 1; x <= N - d1 - d2; x++)
					ans = min(getPopuSub(x, y, d1, d2), ans);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/17779