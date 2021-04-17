#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<bool> ans;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		vector<int> arr(n), a;
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		a.push_back(-1);
		for (int idx = 0; idx < n; idx++)
		{
			if (a.back() >= arr[idx])
			{
				*lower_bound(a.begin(), a.end(), arr[idx]) = arr[idx];
			}
			else
			{
				a.push_back(arr[idx]);
			}
		}
		ans.push_back(a.size() > k);
	}
	for (int c = 1; c <= t; c++)
	{
		cout << "Case #" << c << '\n';
		cout << ans[c - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/12014