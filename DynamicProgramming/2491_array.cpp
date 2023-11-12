#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[100001], dp1[100001], dp2[100001], ans = 0;
int solve1(int idx)
{
	if (idx == N - 1) return 0;
	int& ret = dp1[idx];
	if (ret >= 0) return ret;
	if (A[idx + 1] >= A[idx])
		return ret = solve1(idx + 1) + 1;
	return 0;
}
int solve2(int idx)
{
	if (idx == N - 1) return 0;
	int& ret = dp2[idx];
	if (ret >= 0) return ret;
	if (A[idx + 1] <= A[idx])
		return ret = solve2(idx + 1) + 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	memset(dp1, -1, sizeof(dp1)); memset(dp2, -1, sizeof(dp2));
	for (int i = 0; i < N; i++)
		ans = max(ans, max(solve1(i) + 1, solve2(i) + 1));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2491