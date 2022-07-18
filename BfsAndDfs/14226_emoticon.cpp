#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int v[2001][2001];
int S, ans;

int main()
{
	memset(v, -1, sizeof(v));
	cin >> S;
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	v[1][0] = 0;
	while (!q.empty())
	{
		int cnt = q.front().first;
		int cp = q.front().second;
		q.pop();
		if (cnt == S)
		{
			ans = v[cnt][cp];
			break;
		}
		if (v[cnt][cnt] < 0)
		{
			v[cnt][cnt] = v[cnt][cp] + 1;
			q.push({ cnt, cnt });
		}
		if (cnt > 0 && v[cnt - 1][cp] < 0)
		{
			v[cnt - 1][cp] = v[cnt][cp] + 1;
			q.push({ cnt - 1, cp });
		}
		if (cnt + cp <= 2000 && v[cnt + cp][cp] < 0)
		{
			v[cnt + cp][cp] = v[cnt][cp] + 1;
			q.push({ cnt + cp, cp });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14226