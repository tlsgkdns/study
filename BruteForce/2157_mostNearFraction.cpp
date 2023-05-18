#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int ansA = 1, ansB = 1, A, B;
double F = 0, C = 1;
const int MAX = 32767;
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	F = (double)A / (double)B;
	for (int m = 1; m <= MAX; m++)
	{
		for (int s = max(1, A * m / B - 1); s <= min(MAX, A * m / B + 1); s++)
		{
			if (gcd(m, s) > 1 || (A == s && B == m)) continue;
			double tmp = (((double)s / (double)m));
			if (abs(F - tmp) < abs(F - C))
			{
				C = tmp;
				ansA = s;
				ansB = m;
			}
			else if (C < tmp) break;
		}
	}
	cout << ansA << " " << ansB << '\n';
}

// https://www.acmicpc.net/problem/2137