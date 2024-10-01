#include <iostream>
#include <queue>
using namespace std;
int N, M, R, A[301][301];

void solve(int sy, int sx, int ey, int ex)
{
	if (sy >= ey || sx >= ex) return;
	queue<int> q;
	for (int i = sx; i < ex; i++) q.push(A[sy][i]);
	for (int i = sy; i < ey; i++) q.push(A[i][ex]);
	for (int i = ex; i > sx; i--) q.push(A[ey][i]);
	for (int i = ey; i > sy; i--) q.push(A[i][sx]);
	int cnt = 2 * ((ey - sy) + (ex - sx));
	for (int i = 0; i < (R % cnt); i++)
	{
		q.push(q.front());
		q.pop();
	}
	for (int i = sx; i < ex; i++)
	{
		A[sy][i] = q.front();
		q.pop();
	}
	for (int i = sy; i < ey; i++)
	{
		A[i][ex] = q.front();
		q.pop();
	}
	for (int i = ex; i > sx; i--)
	{
		A[ey][i] = q.front();
		q.pop();
	}
	for (int i = ey; i > sy; i--)
	{
		A[i][sx] = q.front();
		q.pop();
	}
	solve(sy + 1, sx + 1, ey - 1, ex - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	solve(0, 0, N - 1, M - 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << A[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16927