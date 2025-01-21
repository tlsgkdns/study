#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int A, B, P, Q;
int sl(int a, int b)
{
	if (a == b) return 0;
	if (a < b) return 1;
	return 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	if (A == B)
	{
		A = 1; B = 1;
	}
	else
	{
		while (abs(A - B) % 2 == 0)
		{
			if (A % 2 == 1)
			{
				A++;
				B++;
			}
			else
			{
				A /= 2;
				B /= 2;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		char ans = 'N';
		cin >> P >> Q;
		if (sl(A, B) == sl(P, Q))
		{
			int r1 = A, c1 = B, r2 = P, c2 = Q;
			if (r1 > c1)
			{
				swap(r1, c1);
				swap(r2, c2);
			}
			c1 += r2 - r1;
			r1 = r2;
			int s1 = abs(c1 - r1), s2 = abs(c2 - r2);
			if (s1 > s2) swap(s1, s2);
			if (s1 == s2 || ((s2 % s1) == 0))
			{
				ans = 'Y';
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2541