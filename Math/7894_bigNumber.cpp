#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		double s = 0;
		for (int num = 1; num <= n; num++)
			s += log10(num);
		ans.push_back(s + 1);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/7894