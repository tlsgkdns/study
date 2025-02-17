#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;

void solve2(int cnt);

set<tuple<int, int, int>> S;
int T, N, X[7], arr[7], ans = 0;
void chk(int a, int b, int m, int cnt, int t)
{
	if (arr[a] >= 0 && arr[b] >= 0)
	{
		arr[t] = abs(arr[b] - m * arr[a]);
		solve2(cnt + 1);
		arr[t] = -1;
	}
}
void solve2(int cnt)
{
	if (cnt == 7)
	{
		if (arr[0] <= arr[1] && arr[1] <= arr[2]
			&& arr[0] + arr[1] == arr[3] && arr[1] + arr[2] == arr[4] && arr[0] + arr[2] == arr[5]
			&& arr[0] + arr[1] + arr[2] == arr[6] && S.find({ arr[0], arr[1], arr[2] }) == S.end())
		{
			S.insert({ arr[0], arr[1], arr[2] });
			ans++;
		}
		return;
	}
	if (arr[0] < 0)
	{
		chk(1, 3, 1, cnt, 0);
		chk(4, 6, 1, cnt, 0);
		chk(2, 5, 1, cnt, 0);
	}
	if (arr[1] < 0)
	{
		chk(2, 4, 1, cnt, 1);
		chk(5, 6, 1, cnt, 1);
		chk(0, 3, 1, cnt, 1);
	}
	if (arr[2] < 0)
	{
		chk(1, 4, 1, cnt, 2);
		chk(3, 6, 1, cnt, 2);
		chk(0, 5, 1, cnt, 2);
	}
	if (arr[3] < 0)
	{
		chk(0, 1, -1, cnt, 3);
		chk(2, 6, 1, cnt, 3);
	}
	if (arr[4] < 0)
	{
		chk(1, 2, -1, cnt, 4);
		chk(0, 6, 1, cnt, 4);
	}
	if (arr[5] < 0)
	{
		chk(0, 2, -1, cnt, 5);
		chk(1, 6, 1, cnt, 5);
	}
	if (arr[6] < 0)
	{
		chk(0, 4, -1, cnt, 6);
		chk(1, 5, -1, cnt, 6);
		chk(2, 3, -1, cnt, 6);
	}
}
void solve(int idx)
{
	if (idx == N)
	{
		solve2(N);
		return;
	}
	for (int i = 0; i < 7; i++)
		if (arr[i] < 0)
		{
			arr[i] = X[idx];
			solve(idx + 1);
			arr[i] = -1;
		}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(arr, -1, sizeof(arr));
		S.clear();
		ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> X[i];
		solve(0);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/21818