#include <iostream>
#include <vector>

using namespace std;
int eCnt = 0, N, G[51][51], gCnt = 0, cnt = 0, num = 0, ans = -1;
char ch;
bool v[2501], visited[51];
pair<int, int> dfs(int here)
{
	pair<int, int> ret = { 0, 0 };
	for (int i = 0; i < N; i++)
		if (G[here][i] >= 0 && !v[G[here][i]])
		{
			v[G[here][i]] = true;
			bool f = !visited[i];
			visited[i] = true;
			pair<int, int> tmp = dfs(i);
			ret = { ret.first + tmp.first + f, ret.second + tmp.second + 1 };
		}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			if (ch == 'Y' && G[j][i] == 0) G[i][j] = ++num;
			else if (G[j][i] > 0) G[i][j] = G[j][i];
			else G[i][j] = -1;
		}
	for (int i = 0; i < N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			pair<int, int> p = dfs(i);
			if (p.second == 0) continue;
			gCnt += p.first + 1;
			if (ans >= 0)
				cnt += p.second - p.first - 1;
			else
				cnt += p.second - p.first;
			++ans;
		}
	if (N == 1) cout << 0 << '\n';
	else if (gCnt < N || cnt < 0) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1119