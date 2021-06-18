#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	stack<int> h;
	int n;
	int trap(vector<int>& height) {
		n = height.size();
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int bottom = -1;
			while (!h.empty() && height[h.top()] <= height[i])
			{
				int wid = (i - h.top() - 1);
				int hei = height[h.top()] - bottom;
				ans += wid * hei;
				bottom = max(bottom, height[h.top()]);
				h.pop();
			}
			if (!h.empty()) ans += (i - h.top() - 1) * (height[i] - bottom);
			h.push(i);
		}
		return ans;
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	vector<int> height(n);
	for (int i = 0; i < n; i++)
		cin >> height[i];
	cout << s.trap(height) << '\n';
}

// https://leetcode.com/problems/trapping-rain-water/