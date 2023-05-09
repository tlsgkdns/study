#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
ll arr[1001], ans = 0;
vector<ll> a;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a.push_back(arr[i] + arr[j]);
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			ll t = abs(arr[j] - arr[i]);
			if (*lower_bound(a.begin(), a.end(), t) == t)
				ans = max(max(arr[i], arr[j]), ans);
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2295