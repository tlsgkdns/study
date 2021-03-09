#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 100000000;
int dx[3] = { -1, 0, 1 };
vector<vector<int>> mx, mn;
vector<int> nums;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a1 = -1, a2 = INF; cin >> n;
	mx.resize(2, vector<int>(3, -1)); mn.resize(2, vector<int>(3, INF));
	nums.resize(3);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> nums[j];
			if (i == 0)
			{
				mx[0][j] = nums[j];
				mn[0][j] = nums[j];
			}
		}
		if (i != 0)
		{
			int cur = 1 - (i % 2);
			int nxt = 1 - ((i + 1) % 2);
			mx[nxt][0] = max(mx[cur][0] + nums[0], mx[cur][1] + nums[0]);
			mx[nxt][1] = max(mx[cur][0] + nums[1], max(mx[cur][1] + nums[1], mx[cur][2] + nums[1]));
			mx[nxt][2] = max(mx[cur][1] + nums[2], mx[cur][2] + nums[2]);
			mn[nxt][0] = min(mn[cur][0] + nums[0], mn[cur][1] + nums[0]);
			mn[nxt][1] = min(mn[cur][0] + nums[1], min(mn[cur][1] + nums[1], mn[cur][2] + nums[1]));
			mn[nxt][2] = min(mn[cur][1] + nums[2], mn[cur][2] + nums[2]);
		}
	}

	for (int e : mx[1 - (n % 2)])  if (a1 < e) a1 = e;
	for (int e : mn[1 - (n % 2)])  if (a2 > e) a2 = e;
	cout << a1 << " " << a2 << '\n';
}

// https://www.acmicpc.net/problem/2096

/*
Input also can slide.
My first sliding dynamic programming problem.
*/