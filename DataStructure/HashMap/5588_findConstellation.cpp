#include <iostream>
#include <set>

using namespace std;

int N, M, sx[1001], sy[1001], px[1001], py[1001];

set<pair<int, int>> um, pm;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	for (int i = 0; i < M; i++) cin >> sx[i] >> sy[i];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> px[i] >> py[i];
		pm.insert({ px[i], py[i] });
	}
	for (int idx = 0; idx < N; idx++)
	{
		bool f = true;
		int x = px[idx] - sx[0]; int y = py[idx] - sy[0];
		for (int i = 0; i < M; i++)
		{
			if (pm.find({ sx[i] + x, sy[i] + y }) == pm.end())
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			cout << x << " " << y << '\n';
			break;
		}
	}
}

// https://www.acmicpc.net/problem/5588