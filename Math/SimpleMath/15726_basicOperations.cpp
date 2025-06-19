#include <iostream>
#include <algorithm>

using namespace std;

long double A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	cout << (int)max(A * B / C, A / B * C) << '\n';
}

// https://www.acmicpc.net/problem/15726