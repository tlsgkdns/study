#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000007;
int T, K, W, H, N, D[1002][1002], S[26];
char E[1002][1002], ch;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < H&& x < W;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> K >> W >> H;
		pair<int, int> spos;
		int ans = 0;
		for (int i = 0; i < K; i++)
		{
			cin >> ch >> N;
			S[ch - 'A'] = N;
		}
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				D[i][j] = INF;
				cin >> E[i][j];
				if (E[i][j] == 'E') spos = { i, j };
			}
		D[spos.first][spos.second] = 0;
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ 0, spos });
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			if (!inRange(y, x))
			{
				ans = cost;
				break;
			}
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (inRange(ny, nx))
				{
					int nxtCost = cost + S[E[ny][nx] - 'A'];
					if (D[ny][nx] <= nxtCost) continue;
					D[ny][nx] = nxtCost;
					pq.push({ -nxtCost, {ny, nx} });
				}
				else
					pq.push({ -cost, {ny, nx} });
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9505