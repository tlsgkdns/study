#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
int N, M;
ll ans = -1;
char G[10][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == '0' || G[i][j] == '1' || G[i][j] == '4' || G[i][j] == '9')
				ans = max(ans, (ll)(G[i][j] - '0'));
		}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			for (int r = -N + 1; r < N; r++)
				for (int c = -M + 1; c < M; c++)
				{
					if (r == 0 && c == 0)
						continue;
					string num = "";
					int ny = y, nx = x;
					while (ny >= 0 && nx >= 0 && ny < N && nx < M)
					{
						num.push_back(G[ny][nx]);
						ny += r; nx += c;
						ll n = stoll(num);
						if (sqrt((double)n) == (ll)sqrt((double)n))
							ans = max(ans, n);
					}
				}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1025