#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
double X[1001], Y[1001];
double rat = 0.1, px = 0, py = 0, r = 1e10;
int N, cnt = 10000;

double hyp(double x, double y)
{
	return x * x + y * y;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i];
		px += X[i];
		py += Y[i];
	}
	px /= N; py /= N;
	while (cnt--)
	{
		double maxv = 0, tmp;
		int id = 0;
		for (int i = 0; i < N; i++)
		{
			tmp = hyp(px - X[i], py - Y[i]);
			if (tmp > maxv)
			{
				maxv = tmp;
				id = i;
			}
		}
		r = min(r, maxv);
		px += (X[id] - px) * rat;
		py += (Y[id] - py) * rat;
		rat *= 0.995;
	}
	cout << fixed; cout.precision(3);
	cout << px << " " << py << '\n';
	cout << sqrt(r) << '\n';
}

// https://www.acmicpc.net/problem/2626