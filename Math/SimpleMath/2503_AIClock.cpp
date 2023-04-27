#include <iostream>

using namespace std;

int A, B, C, D, R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D;
	R += A * 3600; R += B * 60; R += C; R += D;
	A = R / 3600; R %= 3600; A %= 24;
	B = R / 60; R %= 60;
	cout << A << " " << B << " " << R << '\n';
}

// https://www.acmicpc.net/problem/2530