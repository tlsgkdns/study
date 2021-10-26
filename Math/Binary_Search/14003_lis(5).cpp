#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr, dp, garb;
int N;
int bSearch(int val)
{
	int l = 0, r = garb.size() - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (garb[mid] >= val) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	cin >> N;
	arr.resize(N); dp.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	garb.push_back(-1000000001);
	for (int i = 0; i < N; i++)
	{
		int idx = garb.size();
		if (garb.back() < arr[i])
			garb.push_back(arr[i]);
		else
		{
			idx = bSearch(arr[i]);
			garb[idx] = arr[i];
		}
		dp[i] = idx;
	}
	int target = garb.size() - 1;
	vector<int> ans(garb.size());
	for (int i = N - 1; i >= 0; i--)
	{
		if (dp[i] == target)
		{
			ans[target] = arr[i];
			target--;
		}
	}
	cout << ans.size() - 1 << '\n';
	for (int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}
// https://www.acmicpc.net/problem/14003