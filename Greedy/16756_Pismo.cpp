#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, A[100001], ans = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (i > 0) ans = min(ans, abs(A[i] - A[i - 1]));
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16756