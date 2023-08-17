#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[601], N, ans = 2100000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 3; j < N; j++)
		{
			int l = i + 1, r = j - 1;
			while (l < r)
			{
				int tmp = (arr[i] + arr[j] - arr[r] - arr[l]);
				ans = min(ans, abs(tmp));
				if (tmp < 0) --r;
				else ++l;
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20366