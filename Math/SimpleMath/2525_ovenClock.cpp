#include <iostream>

using namespace std;

int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	B += C; A += (B / 60);
	A %= 24; B %= 60;
	cout << A << " " << B << '\n';
}

// https://www.acmicpc.net/problem/2525