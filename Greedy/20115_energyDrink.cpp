#include <iostream>
#include <algorithm>

using namespace std;
long long N, X[100001];
double ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> X[i];
	sort(X, X + N);
	for (int i = 0; i < N - 1; i++) ans += X[i];
	ans /= 2;
	cout << fixed; cout.precision(5);
	cout << ans + X[N - 1] << '\n';
}

// https://www.acmicpc.net/problem/20115