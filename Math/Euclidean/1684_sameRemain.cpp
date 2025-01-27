#include <iostream>
#include <cmath>

using namespace std;

int N, A, P = 0, G = 0;

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
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (i > 1) G = gcd(G, abs(P - A));
		else if (i == 1) G = abs(P - A);
		P = A;
	}
	cout << G << '\n';
}

// https://www.acmicpc.net/problem/1684