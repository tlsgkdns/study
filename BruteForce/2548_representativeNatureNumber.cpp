#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, s = 20001, e = 0, ans = 0, sub = 1000000000, sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		s = min(nums[i], s);
		e = max(nums[i], e);
	}
	for (int n = s; n <= e; n++)
	{
		sum = 0;
		for (int i = 0; i < N; i++)
			sum += abs(nums[i] - n);
		if (sub > sum)
		{
			sub = sum;
			ans = n;
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2548