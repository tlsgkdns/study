#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> arr1, arr2, s1, s2;
int N, S, num;
ll ans = 0;
void dfs(vector<int>& arr, vector<int>& s, int idx, int sum)
{
	if (idx == arr.size())
	{
		s.push_back(sum);
		return;
	}
	dfs(arr, s, idx + 1, sum + arr[idx]);
	dfs(arr, s, idx + 1, sum);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i <= (N / 2)) arr1.push_back(num);
		else arr2.push_back(num);
	}
	dfs(arr1, s1, 0, 0); dfs(arr2, s2, 0, 0);
	sort(s2.begin(), s2.end());
	for (int i = 0; i < (int)s1.size(); i++)
	{
		auto tmp = lower_bound(s2.begin(), s2.end(), S - s1[i]);
		auto tmp2 = upper_bound(s2.begin(), s2.end(), S - s1[i]);
		if (tmp == s2.end()) continue;
		if (*tmp == S - s1[i]) ans += (tmp2 - tmp);
	}
	if (S == 0) ans--;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1208