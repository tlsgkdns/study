#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, sum = 0, ans = 0;
	cin >> n;
	vector<int> rope(n);
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
		sum += rope[i];
	}
	sort(rope.begin(), rope.end());
	ans = rope[0] * n;
	for (int i = 0; i < n; i++)
	{
		int k = n - i;
		int w = rope[i] * k;
		ans = max(ans, w);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2217

/*
sort and greedy
*/