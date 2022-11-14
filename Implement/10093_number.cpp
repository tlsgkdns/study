#include <iostream>

using namespace std;
using ll = long long;
ll A, B;
int main()
{
	cin >> A >> B;
	if (A > B) swap(A, B);
	if (A == B) cout << 0 << '\n';
	else cout << (B - A - 1) << '\n';
	for (ll a = A + 1; a < B; a++) cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10093