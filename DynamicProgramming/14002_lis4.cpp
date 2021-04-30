#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v, dp, arr;
int n;
int part(int s)
{
	int& ret = dp[s];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = s + 1; next < v.size(); ++next)
	{
		if (v[s] < v[next])
			ret = max(ret, part(next) + 1);
	}
	return ret;
}
void reconstruct(int st)
{
	int r = dp[st];
	arr.push_back(v[st]);
	if (r == 1) return;
	for (int i = st; i < n; i++)
	{
		if (r == dp[i] + 1)
		{
			reconstruct(i);
			break;
		}
	}
}
int main()
{
	cin >> n;
	v.resize(n); dp.resize(n, -1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ret = 0;

	for (int s = 0; s < n; s++)
		ret = max(part(s), ret);
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == ret)
		{
			reconstruct(i);
			break;
		}
	}
	cout << ret << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/14002