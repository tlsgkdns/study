#include <iostream>

using namespace std;
string N;
int S, T;
int U[9] = { 100, 96, 89, 86, 79, 76, 69, 66, 59 };
int D[9] = { 97, 90, 87, 80, 77, 70, 67, 60, 0 };
string G[9] = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> S;
		for (int i = 0; i < 9; i++)
			if (S >= D[i] && S <= U[i])
			{
				cout << N << " " << G[i] << '\n';
				break;
			}
	}
}

// https://www.acmicpc.net/problem/11367