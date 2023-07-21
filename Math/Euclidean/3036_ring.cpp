#include <iostream>
using namespace std;

int R[101], N;
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
	for (int i = 0; i < N; i++) cin >> R[i];
	for (int i = 1; i < N; i++)
	{
		int g = gcd(R[0], R[i]);
		cout << R[0] / g << "/" << R[i] / g << '\n';
	}
}

// https://www.acmicpc.net/problem/3036