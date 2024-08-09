#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N, S[3], v[61][61][61];
int att[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(S[0], S[1], S[2]));
	memset(v, -1, sizeof(v));
	v[S[0]][S[1]][S[2]] = 0;
	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		int nxt = v[a][b][c];
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int na = max(0, a - att[i][0]);
			int nb = max(0, b - att[i][1]);
			int nc = max(0, c - att[i][2]);
			if (v[na][nb][nc] < 0)
			{
				v[na][nb][nc] = nxt + 1;
				q.push(make_tuple(na, nb, nc));
			}
		}
	}
	cout << v[0][0][0] << '\n';
}

// https://www.acmicpc.net/problem/12869