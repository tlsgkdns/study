#include <iostream>
#include <queue>

using namespace std;

int G[4][4], N;
bool v[4][4];
string ans = "Hing\n";
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> G[i][j];
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == N - 1 && x == N - 1)
		{
			ans = "HaruHaru\n";
			break;
		}
		if (y < 0 || x < 0 || y >= N || x >= N || v[y][x]) continue;
		v[y][x] = true;
		q.push({ y + G[y][x], x });
		q.push({ y, x + G[y][x] });
	}
	cout << ans;
}

// https://www.acmicpc.net/problem/16173