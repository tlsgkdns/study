#include <iostream>

using namespace std;

int A, B, C, D, E, F;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D >> E >> F;
	for (int x = -999; x <= 999; x++)
		for (int y = -999; y <= 999; y++)
			if (A * x + B * y == C && D * x + E * y == F)
			{
				cout << x << " " << y << '\n';
				break;
			}
}

// https://www.acmicpc.net/problem/19532