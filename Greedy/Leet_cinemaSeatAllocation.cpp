#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	unordered_map<int, vector<int>> um;
	bool isVacant(int left, int right, vector<int>& row)
	{
		for (int r : row)
			if (left <= r && right >= r) return false;
		return true;
	}
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		for (vector<int> reserve : reservedSeats)
		{
			if (reserve[1] == 1 || reserve[1] == 10) continue;
			um[reserve[0]].push_back(reserve[1]);
		}
		int ans = (n - um.size()) * 2, leng = 0;
		for (auto& rows : um)
		{
			vector<int> row = rows.second;
			if (isVacant(2, 5, row) || isVacant(4, 7, row) || isVacant(6, 9, row))
				ans++;
		}

		return ans;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> res(m, vector<int>(2));
	for (int i = 0; i < m; i++)
		cin >> res[i][0] >> res[i][1];
	Solution s;
	cout << s.maxNumberOfFamilies(n, res) << '\n';
}

// https://leetcode.com/problems/cinema-seat-allocation/