#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	int l = 0, r = n;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (nums[m] >= t) r = m;
		else l = m + 1;
	}
	cout << l << '\n';
}

// https://leetcode.com/problems/search-insert-position/