#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<long long> d;
long long n, k;
long double ans = 999999999.0;
long double getDiv(int f, int b, long double mean)
{
	long double a = 0;
	for (int i = f; i <= b; i++)
		a += pow(d[i] - mean, 2);
	long long sz = (b - f + 1);
	a /= sz;
	long double ret = sqrt(a);
	return ret;
}
int main()
{
	cin >> n >> k;
	d.resize(n);
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = k - 1; i < n; i++)
	{
		for (int j = 0; j <= n - k; j++)
		{
			long long sum = 0;
			int sz = i - j + 1;
			if (sz < k) break;
			for (int u = j; u <= i; u++)
				sum += d[u];
			long double mean = (long double)sum / (long double)sz;
			ans = min(getDiv(j, i, mean), ans);
		}
	}
	cout.precision(12);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/15954