#include <cstring>
#include <iostream>

using namespace std;

int N, M;
bool d[10];

int main()
{
	while (true)
	{
		cin >> N >> M;
		if (cin.eof()) break;
		int ans = 0;
		for (int n = N; n <= M; n++)
		{
			memset(d, false, sizeof(d));
			int t = n, cnt = 1;
			while (t > 0)
			{
				if (d[t % 10])
				{
					cnt = 0;
					break;
				}
				d[t % 10] = true;
				t /= 10;
			}
			ans += cnt;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/5671