#include <iostream>
#include <vector>
using namespace std;
vector<int> interval, tree;
int gcd(int a, int b)
{
	if (a < b) gcd(b, a);
	while (b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	int n, ans = 0;
	cin >> n; tree.resize(n); interval.resize(n - 1);
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	for (int i = 0; i < n - 1; i++)
		interval[i] = tree[i + 1] - tree[i];
	int div = interval[0];
	for (int i = 1; i < n - 1; i++)
		div = gcd(interval[i], div);
	for (int val : interval)
		ans += (val / div) - 1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2485

/*
easy gcd problem
*/