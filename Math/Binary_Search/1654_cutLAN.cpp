#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using ll = long long;
int N, K;
vector<int> lan;
bool canCut(ll leng)
{
	ll ret = 0;
	for (int i = 0; i < N; i++)
		ret += (lan[i] / leng);
	return ret >= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	lan.resize(N);
	for (int i = 0; i < N; i++)
		cin >> lan[i];
	ll l = 0, r = numeric_limits<ll>::max();
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;
		if (canCut(m)) l = m;
		else r = m;
	}
	cout << l << '\n';
}
// https://www.acmicpc.net/problem/1654