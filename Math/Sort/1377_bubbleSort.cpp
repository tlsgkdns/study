#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans = -1;
vector<int> arr;
vector<pair<int, int>> srt;
int main()
{
	cin >> n; arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		srt.push_back({ arr[i], i });
	}
	stable_sort(srt.begin(), srt.end());
	for (int i = 0; i < n; i++)
		ans = max(srt[i].second - i, ans);
	cout << ans + 1 << '\n';
}

// https://www.acmicpc.net/problem/1377