#include <iostream>
#include <algorithm>

using namespace std;

int N, A[3], g;
int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (i == 0) g = A[i];
		else g = gcd(g, A[i]);
	}
	for (int i = 1; i + i <= g; i++)
	{
		bool f = true;
		for (int idx = 0; idx < N && f; idx++)
			if (A[idx] % i != 0)
			{
				f = false;
			}
		if (f) cout << i << '\n';
	}
	cout << g << '\n';
}

// https://www.acmicpc.net/problem/5618