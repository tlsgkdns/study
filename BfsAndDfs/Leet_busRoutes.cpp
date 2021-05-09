#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
		unordered_map<int, vector<int>> um;
		for (int i = 0; i < routes.size(); i++)
			for (int j = 0; j < routes[i].size(); j++)
				um[routes[i][j]].push_back(i);

		queue<pair<int, int>> q;
		vector<bool> v(100001, false);
		int ans = -1;
		q.push(make_pair(source, 0));
		while (!q.empty())
		{
			int t = q.front().first;
			int cnt = q.front().second;
			q.pop();
			if (t == target)
			{
				ans = cnt;
				break;
			}
			for (int r : um[t])
			{
				if (v[r]) continue;
				v[r] = true;
				for (int i = 0; i < routes[r].size(); i++)
				{
					if (routes[r][i] == t) continue;
					q.push(make_pair(routes[r][i], cnt + 1));
				}
			}
		}
		return ans;
	}
};
// https://leetcode.com/problems/bus-routes/