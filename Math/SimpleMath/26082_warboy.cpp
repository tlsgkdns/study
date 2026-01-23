#include <iostream>

using namespace std;
int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	cout << B / A * C * 3 << '\n';
}

// https://www.acmicpc.net/problem/26082