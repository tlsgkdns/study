#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[8], N, ans = 0;
vector<int> arr;
bool used[8];
void solve(int idx)
{
	if (idx >= N)
	{
		int s = 0;
		for (int i = 0; i < N - 1; i++)
			s += abs(arr[i] - arr[i + 1]);
		ans = max(s, ans);
	}
	for (int i = 0; i < N; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		arr.push_back(A[i]);
		solve(idx + 1);
		used[i] = false;
		arr.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10819