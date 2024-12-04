#include <iostream>
#include <cmath>
using namespace std;

int SX, SY, DX, DY, EX, EY, S = 1e9 + 7;
int gcd(int a, int b)
{
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> SX >> SY;
	cin >> EX >> EY >> DX >> DY;
	int g = gcd(DX, DY);
	DX /= g; DY /= g;
	while (true)
	{
		int dist = pow(EX - SX, 2) + pow(EY - SY, 2);
		if (dist >= S) break;
		S = dist;
		EX += DX; EY += DY;
	}
	cout << EX - DX << " " << EY - DY << '\n';
}

// https://www.acmicpc.net/problem/1393