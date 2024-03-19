#include <iostream>

using namespace std;

int R, G;

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b > 0)
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
	cin >> R >> G;
	int g = gcd(R, G);
	for (int i = 1; i <= (g / 2); i++)
		if (g % i == 0)
			cout << i << " " << R / i << " " << G / i << '\n';
	cout << g << " " << R / g << " " << G / g << '\n';
}

// https://www.acmicpc.net/problem/2942