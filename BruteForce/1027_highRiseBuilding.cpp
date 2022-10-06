#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[50], ans = 0;

double getSlide(int b1, int b2)
{
	return (double)(arr[b2] - arr[b1]) / (double)(b2 - b1);
}
bool solve(int b1, int b2)
{
	if (b1 > b2) return solve(b2, b1);
	double s = getSlide(b1, b2);
	for (int i = b1 + 1; i < b2; i++)
		if (s <= getSlide(b1, i))
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			cnt += solve(i, j);
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1027