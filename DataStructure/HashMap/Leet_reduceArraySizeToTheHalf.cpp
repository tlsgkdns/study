#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int minSetSize(vector<int>& arr) {
		unordered_map<int, int> m;
		int t = 0, ret = 0, half = arr.size() / 2;
		vector<int> v;
		for (int a : arr) m[a]++;
		for (pair<int, int> p : m)
			v.push_back(p.second);
		sort(v.begin(), v.end(), greater<int>());
		for (int e : v)
		{
			t += e;
			ret++;
			if (t >= half) break;
		}
		return ret;
	}
};

int main()
{
	int n;
	Solution* s = new Solution();
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << s->minSetSize(arr) << '\n';
}
// https://leetcode.com/problems/reduce-array-size-to-the-half/