#include <iostream>

using namespace std;

int T, N, C;
double G;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int A1 = 0;
		double A2 = 0;
		for (int i = 0; i < N; i++)
		{

			cin >> C >> G;
			A1 += C; A2 += (G * C);
		}
		A2 /= A1;
		cout << A1 << " " << A2 << '\n';
	}
}

// https://www.acmicpc.net/problem/10984