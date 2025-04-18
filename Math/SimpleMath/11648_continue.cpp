#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N / 10 > 0)
	{
		int d = 1;
		while (N > 0)
		{
			d *= (N % 10);
			N /= 10;
		}
		N = d;
		++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11648