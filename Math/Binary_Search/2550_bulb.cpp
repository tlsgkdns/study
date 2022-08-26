#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tmp;
int N, nums[10001], S, bulb[10001], dp[10001], arr[10001];
int bSearch(int val)
{
	int l = 0, r = tmp.size() - 1;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (tmp[m] >= val) r = m;
		else l = m + 1;
	}
	return l;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		nums[arr[i] - 1] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		bulb[i] = nums[S - 1];
	}
	tmp.push_back(-1000000001);
	for (int i = 0; i < N; i++)
	{
		int idx = tmp.size();
		if (tmp.back() < bulb[i])
			tmp.push_back(bulb[i]);
		else
		{
			idx = bSearch(bulb[i]);
			tmp[idx] = bulb[i];
		}
		dp[i] = idx;
	}
	int target = tmp.size() - 1;
	vector<int> ans(tmp.size());
	for (int i = N - 1; i >= 0; i--)
		if (dp[i] == target)
		{
			ans[target] = bulb[i];
			target--;
		}
	for (int i = 1; i < (int)ans.size(); i++)
		ans[i] = arr[ans[i]];
	sort(ans.begin(), ans.end());
	cout << (int)ans.size() - 1 << '\n';
	for (int i = 1; i < (int)ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2550