#include <iostream>

using namespace std;

int N, M, A[101], B[101], ans = 0;

bool solve(int idx, int remain, int target)
{
	if (idx == N) return remain == 0;
	if (target < B[idx] || ((target - B[idx]) % A[idx] > 0)) return false;
	return solve(idx + 1, remain - ((target - B[idx]) / A[idx]), target);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i];
	cin >> M;
	for (int l = 1; l <= M; l++)
	{
		int L = (l * A[0]) + B[0];
		if (solve(1, M - l, L))
		{
			ans = L;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1954