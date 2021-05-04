#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int ans, n = nums.size() - 1;
		queue<pair<int, int>> q;
		vector<bool> v(n + 1, false);
		q.push(make_pair(0, 0));
		v[0] = true;
		while (!q.empty())
		{
			int idx = q.front().first;
			int cnt = q.front().second;
			q.pop();
			if (idx == n)
			{
				ans = cnt;
				break;
			}
			int j = nums[idx];
			for (int i = 1; i <= j; i++)
			{
				if (idx - i > 0 && !v[idx - i])
				{
					v[idx - i] = true;
					q.push(make_pair(idx - i, cnt + 1));
				}

				if (idx + i <= n && !v[idx + i])
				{
					v[idx + i] = true;
					q.push(make_pair(idx + i, cnt + 1));
				}

			}
		}
		return ans;
	}
};

// https://leetcode.com/problems/jump-game-ii/