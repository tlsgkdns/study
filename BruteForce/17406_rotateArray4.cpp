#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int N, M, K, R, C, S, ans = INF;

vector<vector<int>> arr;
vector<pair<pair<int, int>, int>> op;

void rotateA(vector<vector<int>>& A, int r, int c, int s)
{
	if (s <= 0) return;
	int tmp1 = A[r - s][c - s], tmp2;
	for (int i = c - s + 1; i <= c + s; i++)
	{
		tmp2 = A[r - s][i];
		A[r - s][i] = tmp1;
		tmp1 = tmp2;
	}
	for (int i = r - s + 1; i <= r + s; i++)
	{
		tmp2 = A[i][c + s];
		A[i][c + s] = tmp1;
		tmp1 = tmp2;
	}
	for (int i = c + s - 1; i >= c - s; i--)
	{
		tmp2 = A[r + s][i];
		A[r + s][i] = tmp1;
		tmp1 = tmp2;
	}
	for (int i = r + s - 1; i >= r - s; i--)
	{
		tmp2 = A[i][c - s];
		A[i][c - s] = tmp1;
		tmp1 = tmp2;
	}
	rotateA(A, r, c, s - 1);
}
int calc(vector<vector<int>>& A)
{
	int ret = INF;
	for (int r = 0; r < N; r++)
	{
		int val = 0;
		for (int c = 0; c < M; c++)
			val += A[r][c];
		ret = min(ret, val);
	}
	return ret;
}

void solve(vector<vector<int>>& A, vector<bool>& v, int d)
{
	if (d == K)
	{
		ans = min(ans, calc(A));
		return;
	}
	vector<vector<int>> t = A;
	for (int i = 0; i < K; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		rotateA(A, op[i].first.first, op[i].first.second, op[i].second);
		solve(A, v, d + 1);
		A = t;
		v[i] = false;
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;

	arr.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < K; i++)
	{
		cin >> R >> C >> S;
		op.push_back(make_pair(make_pair(R - 1, C - 1), S));
	}
	vector<bool> v(K, false);
	solve(arr, v, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17406