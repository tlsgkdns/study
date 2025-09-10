#include <iostream>

using namespace std;

int X, Y, N, q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		q1 += (X > 0 && Y > 0);
		q2 += (X < 0 && Y > 0);
		q3 += (X < 0 && Y < 0);
		q4 += (X > 0 && Y < 0);
		q5 += (X == 0 || Y == 0);
	}
	cout << "Q1: " << q1 << '\n';
	cout << "Q2: " << q2 << '\n';
	cout << "Q3: " << q3 << '\n';
	cout << "Q4: " << q4 << '\n';
	cout << "AXIS: " << q5 << '\n';
}

// https://www.acmicpc.net/problem/9610