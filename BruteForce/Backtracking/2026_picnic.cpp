#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> isFriend;
vector<int> close;

bool isValid(vector<bool> group, int student)
{
	bool ret = true;
	for (int f = 0; f < group.size(); f++)
	{
		if (group[f]) ret = isFriend[student][f];
		if (!ret) break;
	}

	return ret;
}

int makeGroup(int n, int k, vector<bool>& group, int cnt, int start)
{
	int ret = 0;
	if (cnt == k || n - start < k - cnt) return cnt;

	for (int next = start; next <= n; next++)
	{
		if (!group[next] && isValid(group, next) && close[next] >= k - 1)
		{
			group[next] = true;
			ret = makeGroup(n, k, group, cnt + 1, next);
			if (ret == k) break;
			group[next] = false;
		}
	}

	return ret;
}
int main()
{
	int n, k, f;
	cin >> k >> n >> f;
	isFriend.resize(n + 1, vector<bool>(n + 1, false));
	close.resize(n + 1, 0);
	vector<bool> group(n + 1);

	for (int i = 0; i < f; i++)
	{
		int x, y;
		cin >> x >> y;
		isFriend[x][y] = true;
		isFriend[y][x] = true;
		close[x]++;
		close[y]++;
	}
	int ret;
	ret = makeGroup(n, k, group, 0, 1);
	if (ret < k) cout << -1 << endl;
	else
		for (int i = 1; i < n + 1; i++)
		{
			if (group[i])
				cout << i << '\n';
		}
}

// https://www.acmicpc.net/problem/2026