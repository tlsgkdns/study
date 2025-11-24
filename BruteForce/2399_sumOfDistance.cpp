#include <iostream>
#include <cmath>

using namespace std;
int N;
long long A[10001], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			ans += abs(A[i] - A[j]);
	ans *= 2;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2399