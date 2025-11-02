#include <iostream>
#include <algorithm>

using namespace std;
int T, Y = 0, K = 0, a, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 9; i++)
		{
			cin >> a >> b;
			Y += a; K += b;
		}
		if (Y < K) cout << "Korea\n";
		else if (Y == K) cout << "Draw\n";
		else cout << "Yonsei\n";
	}
}

// https://www.acmicpc.net/problem/10214