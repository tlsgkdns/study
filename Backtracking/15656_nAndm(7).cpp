#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, arr[8];
vector<int> ans;
void solve()
{
	if ((int)ans.size() == M)
	{
		for (int i = 0; i < M; i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		ans.push_back(arr[i]);
		solve();
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
	solve();
}

// https://www.acmicpc.net/problem/15656