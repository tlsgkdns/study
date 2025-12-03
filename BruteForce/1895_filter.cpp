#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int R, C, T, P[41][41], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> P[i][j];
	cin >> T;
	for (int sy = 0; sy <= R - 3; sy++)
		for (int sx = 0; sx <= C - 3; sx++)
		{
			vector<int> a;
			for (int y = sy; y < sy + 3; y++)
				for (int x = sx; x < sx + 3; x++)
					a.push_back(P[y][x]);
			sort(a.begin(), a.end());
			ans += (a[4] >= T);
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1895