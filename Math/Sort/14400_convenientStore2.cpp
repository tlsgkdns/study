#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
ll N, X[100001], Y[100001], sx = 0, sy = 0, ansx = 0, ansy = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i];
	}
	sort(X, X + N);
	sort(Y, Y + N);
	for (int i = 1; i < N; i++) sx += abs(X[i] - X[0]);
	ansx = sx;
	for (int i = 1; i < N; i++)
	{
		ll sub = abs(X[i] - X[i - 1]);
		sx += sub * i;
		sx -= (N - i) * sub;
		ansx = min(ansx, sx);
	}
	for (int i = 1; i < N; i++) sy += abs(Y[i] - Y[0]);
	ansy = sy;
	for (int i = 1; i < N; i++)
	{
		ll sub = abs(Y[i] - Y[i - 1]);
		sy += sub * i;
		sy -= (N - i) * sub;
		ansy = min(ansy, sy);
	}
	cout << ansx + ansy << '\n';
}

// https://www.acmicpc.net/problem/14400