#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A, cnt[10001];
vector<int> arr, n;

void solve()
{
	if (n.size() == M)
	{
		for (int i = 0; i < M; i++) cout << n[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (cnt[arr[i]] == 0) continue;
		--cnt[arr[i]];
		n.push_back(arr[i]);
		solve();
		n.pop_back();
		++cnt[arr[i]];
	}
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
	solve();
}

// https://www.acmicpc.net/problem/15663