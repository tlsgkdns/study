#include <iostream>

using namespace std;

int A, B, C, D;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> A >> B >> C >> D;
	cout << A * 56 + B * 24 + C * 14 + 6 * D << '\n';
}

// https://www.acmicpc.net/problem/20254