#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ans;
int N, M, arr[10];

void solve(int idx)
{
	if (ans.size() == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = idx; i < N; i++)
	{
		ans.push_back(arr[i]);
		solve(i);
		ans.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	solve(0);
}

// https://www.acmicpc.net/problem/15657