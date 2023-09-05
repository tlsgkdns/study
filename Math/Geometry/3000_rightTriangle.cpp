#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll N, X, Y, H[100001], V[100001];
vector<pair<ll, ll>> L;
ll ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		++V[X]; ++H[Y];
		L.push_back({ X, Y });
	}
	for (int i = 0; i < N; i++)
		ans += (V[L[i].first] - 1) * (H[L[i].second] - 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3000