#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stair;
vector<vector<int>> cache;

int up(int n, bool cont)
{
	if (n >= stair.size()) return 0;
	if (n == stair.size() - 1) return stair[n];

	int& ret = cache[n][cont];
	if (ret != -1) return ret;
	int sc = stair[n];

	if (cont && n + 1 == stair.size() - 1) return 0;
	int s1 = (cont) ? 0 : up(n + 1, true);
	int s2 = up(n + 2, false);

	return ret = sc + max(s1, s2);
}
int main()
{
	int n;
	cin >> n;
	stair.resize(n);
	for (int i = 0; i < n; i++) cin >> stair[i];
	cache.resize(n + 1, vector<int>(2, -1));
	int ans = max(up(0, false), up(1, false));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2579