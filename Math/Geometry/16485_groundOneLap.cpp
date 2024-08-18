#include <iostream>

using namespace std;
int D1, D2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D1 >> D2;
	cout << fixed; cout.precision(10);
	cout << D1 * 2 + D2 * 2 * 3.141592 << '\n';
}

// https://www.acmicpc.net/problem/16486