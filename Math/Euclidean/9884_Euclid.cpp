#include <iostream>

using namespace std;

int A, B;

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
	cin >> A >> B;
	cout << gcd(A, B) << '\n';
}

// https://www.acmicpc.net/problem/9884