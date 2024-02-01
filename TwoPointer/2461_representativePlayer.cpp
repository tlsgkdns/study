#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
int l = 0, r = 0, N, M, A, cnt = 0, ans = 1000000007, v[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> A;
			arr.push_back({ A, i });
		}
	sort(arr.begin(), arr.end());
	while (r < arr.size())
	{
		while (r < arr.size() && cnt < N)
		{
			if (v[arr[r].second] == 0) ++cnt;
			++v[arr[r].second]; ++r;
		}
		if (cnt == N) ans = min(ans, arr[r - 1].first - arr[l].first);
		while (l < r && cnt == N)
		{
			if (v[arr[l].second] == 1) --cnt;
			--v[arr[l].second]; ++l;
			if (cnt == N) ans = min(ans, arr[r - 1].first - arr[l].first);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2461