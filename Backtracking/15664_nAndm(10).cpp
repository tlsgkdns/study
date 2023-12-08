#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans, arr;
int N, M, cnt[10001], A;

void solve(int idx)
{
	if (ans.size() == M)
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	if (idx == arr.size()) return;
	if (cnt[arr[idx]] > 0)
	{
		ans.push_back(arr[idx]);
		--cnt[arr[idx]];
		solve(idx);
		++cnt[arr[idx]];
		ans.pop_back();
	}
	solve(idx + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (cnt[A] == 0) arr.push_back(A);
		++cnt[A];
	}
	sort(arr.begin(), arr.end());
	solve(0);
}

// https://www.acmicpc.net/problem/15664