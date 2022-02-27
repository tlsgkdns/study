#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int result[4][6][3];
int tmp[6][3];
int ans[4] = { 0, 0, 0, 0 };
vector<pii> battle;
bool isSame(int idx)
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			if (result[idx][i][j] != tmp[i][j])
				return false;
	return true;
}
void solve(int idx)
{
	if (idx == battle.size())
	{
		for (int i = 0; i < 4; i++)
			if (isSame(i))
				ans[i] = 1;
		return;
	}
	tmp[battle[idx].first][0]++; tmp[battle[idx].second][2]++;
	solve(idx + 1);
	tmp[battle[idx].first][0]--; tmp[battle[idx].second][2]--;
	tmp[battle[idx].first][1]++; tmp[battle[idx].second][1]++;
	solve(idx + 1);
	tmp[battle[idx].first][1]--; tmp[battle[idx].second][1]--;
	tmp[battle[idx].first][2]++; tmp[battle[idx].second][0]++;
	solve(idx + 1);
	tmp[battle[idx].first][2]--; tmp[battle[idx].second][0]--;
}

int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 3; k++)
				cin >> result[i][j][k];
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			battle.push_back({ i, j });
	solve(0);
	for (int i = 0; i < 4; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/6987