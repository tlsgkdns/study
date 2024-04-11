#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

double ans = 0.0, N, S[100001];
double getArea(int idx1, int idx2)
{
	return S[idx1] * S[idx2] * 0.5 * sin(2 * M_PI / (N));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	sort(S, S + (int)N);
	ans += getArea(N - 1, N - 2) + getArea(0, 1);
	for (int i = N - 3; i >= 0; i--) ans += getArea(i + 2, i);
	cout << fixed; cout.precision(3);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13869