#include <iostream>
#include <algorithm>

using namespace std;
long long S, K, ans = 1, d = 0, r = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> K;
	d = S / K; r = S % K;
	for (int i = 0; i < r; i++) ans *= (d + 1);
	for (int i = 0; i < K - r; i++) ans *= d;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1500