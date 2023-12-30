#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

string E;

ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	while (b != 0)
	{
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> E;
		if (cin.eof()) break;
		double N = 0, C = 0, D = 0.1;
		int circularCnt = 0, notCircularCnt = 0;
		bool F = false, B = false;
		for (int i = 0; i < E.size() - 1; i++)
		{
			if (E[i] == '.')
			{
				F = true;
				continue;
			}
			if (E[i] == '(')
			{
				B = true;
				continue;
			}
			if (F)
			{
				if (B)
				{
					C = C * 10 + (E[i] - '0');
					++circularCnt;
				}
				else
					++notCircularCnt;
				N += D * (E[i] - '0');
				D *= 0.1;
			}
			else
				N = (10 * N + (E[i] - '0'));
		}
		int mother = 0;
		double son = N;
		for (int i = 0; i < circularCnt; i++) mother = mother * 10 + 9;
		if (notCircularCnt == 0)
		{
			for (int i = 0; i < circularCnt; i++) son *= 10;
			son -= floor(N);
		}
		else
		{
			for (int i = 0; i < notCircularCnt; i++)
			{
				mother *= 10;
				son *= 10;
			}
			double tmp = son;
			for (int i = 0; i < circularCnt; i++) son *= 10;
			son -= floor(tmp);
		}
		ll g = gcd(round(son), round(mother));
		cout << E << " = " << ((ll)round(son) / g) << " / " << ((ll)round(mother) / g) << '\n';
	}
}

// https://www.acmicpc.net/problem/9734