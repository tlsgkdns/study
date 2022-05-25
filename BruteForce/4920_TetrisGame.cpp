#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N;
pii shape[13][4] = { {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
					{{0, 0}, {0, 1}, {0, 2}, {0, 3}},

					{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
					{{0, 1}, {1, 1}, {1, 0}, {2, 0}},

					{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
					{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
					{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
					{{0, 0}, {1, 0}, {2, 0}, {0, 1}},

					{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
					{{0, 0}, {1, 0}, {2, 0}, {1, -1}},
					{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
					{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},

					{{0, 0}, {1, 0}, {0, 1}, {1, 1}} };
vector<ll> ans;
ll grid[101][101];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> grid[i][j];
		ll a = -10000000001;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				for (int i = 0; i < 13; i++)
				{
					ll tmp = 0;
					int j = 0;
					for (; j < 4; j++)
					{
						int ny = y + shape[i][j].first;
						int nx = x + shape[i][j].second;
						if (!inRange(ny, nx)) break;
						tmp += grid[ny][nx];
					}
					if (j < 4) continue;
					a = max(a, tmp);
				}
		ans.push_back(a);
	}
	for (int i = 0; i < (int)ans.size(); i++)
		cout << i + 1 << ". " << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/4920