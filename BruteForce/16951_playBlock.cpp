#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int A[1001], ans = 1e9 + 7, N, K;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int h = 1; h <= 1000; h++)
	{
		int s = 0;
		for (int i = 0; i < N; i++)
			s += (A[i] != (i * K + h));
		ans = min(ans, s);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16951