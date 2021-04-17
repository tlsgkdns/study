#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
int t, n, m;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int s = 0;
		cin >> n >> m;
		vector<int> A(n), B(m);
		for (int j = 0; j < n; j++) cin >> A[j];
		for (int j = 0; j < m; j++) cin >> B[j];
		sort(B.begin(), B.end());
		for (int j = 0; j < n; j++)
		{
			int left = 0, right = m - 1;
			auto it = lower_bound(B.begin(), B.end(), A[j]);
			s += it - B.begin();
		}
		ans.push_back(s);
	}
	for (int a : ans)	cout << a << '\n';
}

// https://www.acmicpc.net/problem/7795