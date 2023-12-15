#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> P;
ll N, X, A;
ll S = 0, ans = 0, tmp = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> A;
		P.push_back({ X, A });
		S += P[i].second;
	}
	sort(P.begin(), P.end());
	if (S % 2) S += 2;
	S /= 2L;
	while (true)
	{
		tmp += P[ans++].second;
		if (tmp >= S) break;
	}
	cout << P[ans - 1].first << '\n';
}

// https://www.acmicpc.net/problem/2141