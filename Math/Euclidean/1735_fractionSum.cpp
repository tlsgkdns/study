#include <iostream>
using namespace std;
int A, B, C, D;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	cin >> A >> B >> C >> D;
	int down = (B * D) / gcd(B, D), up = (down / B) * A + (down / D) * C;
	int g = gcd(down, up);
	cout << (up / g) << " " << (down / g) << '\n';
}

// https://www.acmicpc.net/problem/1735