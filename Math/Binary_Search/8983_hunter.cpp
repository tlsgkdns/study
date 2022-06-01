#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> animal;
vector<int> loc;
int M, N, L, U, D, C, ans = 0;
int bSearch(int val, bool up)
{
	int l = 0, r = M - 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (loc[m] <= animal[val].first) l = m;
		else r = m;
	}
	if (up) return r;
	return l;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> L;
	loc.resize(M); animal.resize(N);
	for (int i = 0; i < M; i++)	cin >> loc[i];
	for (int i = 0; i < N; i++) cin >> animal[i].first >> animal[i].second;
	sort(loc.begin(), loc.end());
	for (int i = 0; i < N; i++)
	{
		D = loc[bSearch(i, false)];
		U = loc[bSearch(i, true)];
		C = (abs(U - animal[i].first) > abs(animal[i].first - D)) ? D : U;
		ans += (abs(C - animal[i].first) + animal[i].second <= L);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/8983