#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 500;
int tiles[SIZE + 1][SIZE + 1];
int dy[6] = { -1, 1, 2, 1, -1, -2 };
int dx[6] = { -2, -2, 0, 2, 2, 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int center = SIZE / 2;
	vector<int> order, ans;
	int c, n;
	cin >> c;
	vector<int> resources(5, 0);
	pair<int, int> pos = { center - 1, center + 2 };
	int posIdx = 0; order.push_back(1);
	tiles[center][center] = 1; resources[0]++;
	while (order.size() < 10000)
	{
		vector<bool> sel(5, false);
		int s = 0;
		for (int i = 0; i < 6; i++)
		{
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];
			if (tiles[ny][nx] == 0) continue;
			sel[tiles[ny][nx] - 1] = true;
		}
		for (int i = 0; i < 5; i++)
		{
			if (sel[i]) continue;
			s = i; break;
		}
		for (int i = 0; i < 5; i++)
			if (!sel[i] && resources[i] < resources[s]) s = i;
		tiles[pos.first][pos.second] = s + 1; resources[s]++;
		order.push_back(s + 1);
		int np = (posIdx + 1) % 6;
		if (tiles[pos.first + dy[np]][pos.second + dx[np]] == 0) posIdx = np;
		pos.first += dy[posIdx]; pos.second += dx[posIdx];
	}

	for (int i = 0; i < c; i++)
	{
		cin >> n;
		ans.push_back(order[n - 1]);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/3678