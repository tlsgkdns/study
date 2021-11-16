#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> bowl;
vector<int> fl;
int N, K, start = 0;

int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

void addFish()
{
	int m = *min_element(bowl[0].begin(), bowl[0].end());
	for (int i = 0; i < N; i++)
		if (m == bowl[0][i])
			bowl[0][i]++;
}

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
void stackBowl(int s, int e, int h)
{
	if (e + h > N) return;
	int w = e - s;
	vector<vector<int>> tmp(w, vector<int>(h, 0)), tmp2(h, vector<int>(w, 0));
	for (int i = 0; i < h; i++)
		for (int j = s; j < e; j++)
		{
			tmp2[i][j - s] = bowl[i][j];
			bowl[i][j] = 0;
		}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			tmp[j][i] = tmp2[h - i - 1][w - 1 - j];

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			bowl[i + 1][e + j] = tmp[i][h - 1 - j];

	stackBowl(e, e + h, w + 1);
}

void adjustFish()
{
	vector<vector<int>> tmp(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (bowl[i][j] == 0) continue;
			for (int d = 0; d < 2; d++)
			{
				int y = i, x = j;
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(ny, nx) || bowl[ny][nx] == 0) continue;
				if (bowl[ny][nx] > bowl[y][x])
				{
					swap(ny, y); swap(nx, x);
				}
				int sub = (bowl[y][x] - bowl[ny][nx]) / 5;
				tmp[y][x] -= sub; tmp[ny][nx] += sub;
			}
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			bowl[i][j] += tmp[i][j];
}
void setBowlAtFloor()
{
	fl = vector<int>();
	for (int j = 0; j < N; j++)
	{
		if (bowl[0][j] == 0) continue;
		for (int i = 0; i < N; i++)
		{
			if (bowl[i][j] == 0) break;
			fl.push_back(bowl[i][j]);
		}
	}
	bowl = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		bowl[0][i] = fl[i];
}
void stackBowl2()
{
	int w = N;
	int s = 0, e = N / 2;
	for (int h = 1; h < 4; h *= 2)
	{
		w /= 2;
		vector<vector<int>> tmp(h, vector<int>(w, 0)), tmp2(h, vector<int>(w, 0));
		for (int i = 0; i < h; i++)
			for (int j = s; j < e; j++)
			{
				tmp2[i][j - s] = bowl[i][j];
				bowl[i][j] = 0;
			}
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				tmp[i][j] = tmp2[h - 1 - i][w - 1 - j];
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (tmp[i][j] == 0) continue;
				bowl[i + h][e + j] = tmp[i][j];
			}
		s = N / 2; e = s + (w / 2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	bowl.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) cin >> bowl[0][i];
	int ans = 0, sub = *max_element(bowl[0].begin(), bowl[0].end()) - *min_element(bowl[0].begin(), bowl[0].end());
	while (sub > K)
	{
		addFish();
		stackBowl(0, 1, 1);
		adjustFish();
		setBowlAtFloor();
		stackBowl2();
		adjustFish();
		setBowlAtFloor();
		ans++;
		sub = *max_element(bowl[0].begin(), bowl[0].end()) - *min_element(bowl[0].begin(), bowl[0].end());
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/23291