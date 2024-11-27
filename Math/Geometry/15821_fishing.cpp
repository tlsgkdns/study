#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<double> r;
double ans = 0;
int K, N, P, X, Y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	while (K--)
	{
		double ans = 0, l = 0;
		cin >> P;
		for (int i = 0; i < P; i++)
		{
			cin >> X >> Y;
			l = max(l, sqrt(pow(X, 2) + pow(Y, 2)));
		}
		r.push_back(l);
	}
	sort(r.begin(), r.end());
	cout.precision(2);
	cout << fixed;
	cout << pow(r[N - 1], 2) << '\n';
}

// https://www.acmicpc.net/problem/15821