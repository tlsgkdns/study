#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int pizza, n, m, ans = 0;
int main()
{
	cin >> pizza;
	cin >> n >> m;
	vector<int> f(n), s(m), fps(2 * n + 1), sps(2 * m + 1), slicesA, slicesB;
	for (int i = 0; i < n; i++) cin >> f[i];
	for (int i = 0; i < m; i++) cin >> s[i];
	fps[0] = 0; sps[0] = 0;
	for (int i = 1; i <= n; i++)
		fps[i] = fps[i - 1] + f[i - 1];
	for (int i = n + 1; i <= n * 2; i++)
		fps[i] = fps[i - n] + fps[n];
	for (int i = 1; i <= m; i++)
		sps[i] = sps[i - 1] + s[i - 1];
	for (int i = m + 1; i <= m * 2; i++)
		sps[i] = sps[i - m] + sps[m];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= i + n - 1; j++)
		{
			int part = fps[j] - fps[i];
			slicesA.push_back(part);
		}
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= i + m - 1; j++)
		{
			int part = sps[j] - sps[i];
			slicesB.push_back(part);
		}
	slicesA.push_back(fps[n]);	slicesA.push_back(0);
	slicesB.push_back(sps[m]);	slicesB.push_back(0);
	sort(slicesA.begin(), slicesA.end());
	sort(slicesB.begin(), slicesB.end());
	for (int num = 0; num <= pizza; num++)
	{
		int a = upper_bound(slicesA.begin(), slicesA.end(), num)
			- lower_bound(slicesA.begin(), slicesA.end(), num);
		int b = upper_bound(slicesB.begin(), slicesB.end(), pizza - num)
			- lower_bound(slicesB.begin(), slicesB.end(), pizza - num);
		ans += a * b;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2632