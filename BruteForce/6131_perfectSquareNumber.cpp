#include <cmath>
#include <iostream>

using namespace std;

int N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 1; n <= 1000; n++)
	{
		double num = ((n * n) + N);
		int sq = sqrt(num);
		ans += (sq * sq == num);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/6131