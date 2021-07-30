#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
int n;
vector<int> beautifulArray(int n) {
	vector<int> ret = { 1 };
	while (ret.size() < n)
	{
		vector<int> cur;
		for (int num : ret)
			if (num * 2 - 1 <= n)
				cur.push_back(num * 2 - 1);
		for (int num : ret)
			if (num * 2 <= n)
				cur.push_back(num * 2);
		ret = cur;
	}
	return ret;
}
int main()
{
	cin >> n;
	vector<int> ans = beautifulArray(n);
	for (int a : ans) cout << a << " ";
	cout << '\n';
}

// https://leetcode.com/problems/beautiful-array/