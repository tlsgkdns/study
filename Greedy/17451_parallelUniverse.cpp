#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
ll arr[300001], N, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] >= ans) ans = arr[i];
		else ans = ceil((double)((double)ans / (double)arr[i])) * arr[i];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17451