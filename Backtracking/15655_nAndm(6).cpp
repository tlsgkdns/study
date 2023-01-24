#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
int N, M, arr[10];
void solve(int d)
{
	if (d == M)
	{
		for (int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (ans.back() >= arr[i]) continue;
		ans.push_back(arr[i]);
		solve(d + 1);
		ans.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	ans.push_back(-1);
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	solve(0);
}

// https://www.acmicpc.net/problem/15655