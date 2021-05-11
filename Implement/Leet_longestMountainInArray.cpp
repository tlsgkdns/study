#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	int longestMountain(vector<int>& arr) {
		int ans = 0, s = -1, idx = 0;
		bool start = false, up = false;
		for (int i = 0; i < arr.size() - 1; i++)
		{
			if (s == -1 && arr[i] < arr[i + 1])
			{
				s = i;
				up = true;
			}
			else if (s == -1) continue;
			else if (up && arr[i] == arr[i + 1])
			{
				up = false;
				s = -1;
			}
			else if (up && arr[i] > arr[i + 1])
				up = false;
			else if (!up && arr[i] <= arr[i + 1])
			{
				ans = max(ans, i - s + 1);
				s = i;
				if (arr[i] < arr[i + 1]) up = true;
			}
		}
		int l = arr.size() - s;
		if (!up && s != -1)
			ans = max(ans, l);
		if (ans == 1) ans = 0;
		return ans;
	}
};

int main()
{
	int n;
	vector<int> arr;
	cin >> n; arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Solution s;
	cout << s.longestMountain(arr) << '\n';
}

// https://leetcode.com/problems/longest-mountain-in-array/