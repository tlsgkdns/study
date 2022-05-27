#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr, tmp;
vector<bool> v;
int N, M;
void solve()
{
	if (tmp.size() == M)
	{
		for (int i = 0; i < M; i++)
			cout << tmp[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		tmp.push_back(arr[i]);
		solve();
		v[i] = false;
		tmp.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	arr.resize(N); v.resize(N, false);
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	solve();
}

// https://www.acmicpc.net/problem/15654