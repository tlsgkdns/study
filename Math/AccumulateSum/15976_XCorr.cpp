#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
using ll = long long;
ll N, M, A, B, X, Y, L;
vector<ll> index1, arr1, index2, arr2;
ll ans = 0;
int bSearch(ll val)
{
	int l = 0, r = (int)index1.size();
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;
		if (index1[m] < val) l = m;
		else r = m;
	}
	return l;
}

int bSearch2(ll val)
{
	int l = 0, r = (int)index1.size();
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;
		if (index1[m] <= val) l = m;
		else r = m;
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	index1.push_back(-20000000001); arr1.push_back(0);
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		index2.push_back(X + 1);
		arr2.push_back(Y);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		index1.push_back(X + 1);
		arr1.push_back(arr1.back() + Y);
	}
	cin >> A >> B;
	for (int i = 0; i < N; i++)
	{
		int idx1 = bSearch(index2[i] + A);
		int idx2 = bSearch2(index2[i] + B);
		ans += (arr1[idx2] - arr1[idx1]) * arr2[i];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15976