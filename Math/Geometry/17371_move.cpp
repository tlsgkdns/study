#include <iostream>
#include <cmath>

using namespace std;

int N, X[1001], Y[1001], ansx, ansy;
double D = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cout << fixed;
	cout.precision(7);
	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < N; i++)
	{
		double d = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			d = max(d, sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2)));
		}

		if (D >= d)
		{
			D = d;
			ansx = X[i];
			ansy = Y[i];
		}
	}
	cout << ansx << " " << ansy << '\n';
}

// https://www.acmicpc.net/problem/17371