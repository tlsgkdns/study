#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
int dy[9] = { 1, 1, 1, 0, 0, -1, -1, -1, 0 };
int dx[9] = { 0, -1, 1, -1, 1, 0, -1, 1, 0 };
vector<vector<bool>> fungus;
char org;
ll ans = 0, h, w;
int R, C, K;

void grow()
{
	vector<vector<bool>> tmp(fungus);
	for (int i = 0; i < 40 + R; i++)
		for (int j = 0; j < 40 + C; j++)
		{
			if (!fungus[i][j]) continue;
			for (int d = 0; d < 9; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (tmp[ny][nx]) continue;
				tmp[ny][nx] = true;
				ans++;
			}
		}
	fungus = tmp;
}
void getHW()
{
	int sw = 40 + C, ew = -1, sh = 40 + R, eh = -1;
	for (int i = 0; i < (40 + R); i++)
		for (int j = 0; j < (40 + C); j++)
		{
			if (fungus[i][j])
			{
				sw = min(sw, j);
				ew = max(ew, j);
				sh = min(sh, i);
				eh = max(eh, i);
			}
		}
	w = ew - sw + 1;
	h = eh - sh + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> K;
	fungus.resize(R + 40, vector<bool>(C + 40, false));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> org;
			if (org == '.') fungus[i + 20][j + 20] = false;
			else
			{
				fungus[i + 20][j + 20] = true;
				ans++;
			}
		}

	if (K <= 20)
	{
		for (int i = 0; i < K; i++) grow();
		cout << ans << '\n';
	}
	else
	{
		for (int i = 0; i < 20; i++) grow();
		getHW();
		if (ans != 0)
		{
			ll sub = (h * w) - ans;
			h += (K - 20) * 2;
			w += (K - 20) * 2;
			ans = (h * w) - sub;
		}
		cout << ans << '\n';
	}
}

//https://www.acmicpc.net/problem/17788