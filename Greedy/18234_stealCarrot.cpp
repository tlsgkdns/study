#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
vector<pii> C;
ll N, T, W, P, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> P;
		C.push_back({ P, W });
	}
	sort(C.begin(), C.end());
	for (int i = 0; i < N; i++)
		ans += C[i].second + (C[i].first * (T - N + i));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18234