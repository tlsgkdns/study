#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hills;
int N, h, lo = 101, hi = 0;

int getCost(int l, int r)
{
	auto lit = lower_bound(hills.begin(), hills.end(), l);
	auto rit = upper_bound(hills.begin(), hills.end(), r);
	int ret = 0;
	for (auto iter = hills.begin(); iter < lit; iter++)
		ret += ((l - *iter) * (l - *iter));
	for (auto iter = rit; iter < hills.end(); iter++)
		ret += ((r - *iter) * (r - *iter));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h;
		hills.push_back(h);
		lo = min(h, lo);
		hi = max(hi, h);
	}
	sort(hills.begin(), hills.end());
	int ans = 1000000000;
	for (int s = lo; s + 17 <= hi; s++)
		ans = min(ans, getCost(s, s + 17));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/9881