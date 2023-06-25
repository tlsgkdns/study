#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll N, T[100001];

bool solve(int interv)
{
	vector<ll> arr;
	ll cnt = 0;
	for (int i = 0; i < N; i++)
		if (interv < T[i]) arr.push_back(T[i]);
		else ++cnt;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % interv > 0) arr[i] -= arr[i] % interv;
		else arr[i] -= interv;
		cnt -= (arr[i] / interv);
		if (cnt < 0) return false;
		++cnt;
	}
	return cnt >= 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	ll l = 10000000000000, r = 10000000000000;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
		l = min(T[i], l);
	}
	--l;
	sort(T, T + N);
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) r = m;
		else l = m;
	}
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/17383