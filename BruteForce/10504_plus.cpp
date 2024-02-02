#include <iostream>
#include <cmath>
using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int sq = sqrt(N);
		bool f = true;
		for (int l = 2; ((l * (l + 1)) / 2) <= N; l++)
		{
			int a = (N / l) - ((l + 1) / 2);
			if (((l * (l + 1)) / 2) + a * l == N)
			{
				f = false;
				cout << N << " = ";
				for (int n = 1; n <= l; n++)
				{
					cout << n + a;
					if (n != l) cout << " + ";
					else cout << '\n';
				}
				break;
			}
		}
		if (f) cout << "IMPOSSIBLE\n";
	}
}

// https://www.acmicpc.net/problem/10504