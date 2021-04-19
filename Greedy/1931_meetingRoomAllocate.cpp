#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, s = 0, ans = 1;
	cin >> n;
	vector<pair<int, int>> t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i].second >> t[i].first;
	sort(t.begin(), t.end());
	int m = t[0].first;
	for (int i = 1; i < n; i++)
		if (m <= t[i].second)
		{
			m = t[i].first;
			ans++;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1931