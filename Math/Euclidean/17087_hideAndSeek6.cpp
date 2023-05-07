#include <iostream>
#include <cmath>

using namespace std;

int A[100001], N, S;

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
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		A[i] = abs(A[i] - S);
	}
	int G = A[0];
	for (int i = 1; i < N; i++)
		G = gcd(G, A[i]);
	cout << G << '\n';
}

// https://www.acmicpc.net/problem/17087