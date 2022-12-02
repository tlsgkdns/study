#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
int A[301][301], ans[301][301];

void solve(int r1, int c1, int r2, int c2)
{
	if (r1 >= r2 || c1 >= c2) return;
	vector<int> arr;
	for (int i = c1; i <= c2; i++) arr.push_back(A[r1][i]);
	for (int i = r1 + 1; i <= r2; i++) arr.push_back(A[i][c2]);
	for (int i = c2 - 1; i >= c1; i--) arr.push_back(A[r2][i]);
	for (int i = r2 - 1; i > r1; i--) arr.push_back(A[i][c1]);
	int idx = 0;
	rotate(arr.begin(), arr.begin() + (R % (int)arr.size()), arr.end());
	for (int i = c1; i <= c2; i++) ans[r1][i] = arr[idx++];
	for (int i = r1 + 1; i <= r2; i++) ans[i][c2] = arr[idx++];
	for (int i = c2 - 1; i >= c1; i--) ans[r2][i] = arr[idx++];
	for (int i = r2 - 1; i > r1; i--) ans[i][c1] = arr[idx++];
	solve(r1 + 1, c1 + 1, r2 - 1, c2 - 1);
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
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16926