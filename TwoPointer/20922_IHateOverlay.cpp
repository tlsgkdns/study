#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K;
int arr[200001], l = 0, r = 1;
int cnt[100001], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(cnt, 0, sizeof(cnt));
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cnt[arr[0]]++;
	while (r < N)
	{
		cnt[arr[r]]++;
		r++;
		while (cnt[arr[r - 1]] > K&& l < r)
		{
			cnt[arr[l]]--;
			l++;
		}
		ans = max((r - l), ans);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20922