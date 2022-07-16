#include <iostream>

using namespace std;
using ll = long long;
int N;
ll ans = 0;
int arr[100001];
bool v[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int l = 0, r = 1;
	v[arr[l]] = true;
	while (true)
	{
		ans += (ll)(r - l);
		if (r == N) break;
		while (l < r && v[arr[r]])
		{
			v[arr[l]] = false;
			l++;
		}
		v[arr[r]] = true; a
			r++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13144