#include <iostream>
#include <vector>
using namespace std;

int D1, D2, ans = 0;
bool v[2001];
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b > 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D1 >> D2;
	for (int n = D1; n <= D2; n++)
	{
		ans += n;
		vector<int> tmp;
		for (int i = 1; i <= n; i++)
		{
			int g = gcd(n, i);
			if (v[n / g])
				--ans;
			else
				tmp.push_back(n / g);
		}
		for (int i = 0; i < tmp.size(); i++)
			v[tmp[i]] = true;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/10166