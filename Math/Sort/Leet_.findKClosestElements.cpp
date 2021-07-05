#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num;
bool cmp(int a, int b)
{
	if (abs(a - num) == abs(b - num)) return a < b;
	return abs(a - num) < abs(b - num);
}
class Solution {
public:

	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		num = x;
		sort(arr.begin(), arr.end(), cmp);
		vector<int> ret(arr.begin(), arr.begin() + k);
		sort(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Solution s;
	vector<int> ans = s.findClosestElements(arr, k, x);
	for (int a : ans)
		cout << a << " ";
}

//https://leetcode.com/problems/find-k-closest-elements/