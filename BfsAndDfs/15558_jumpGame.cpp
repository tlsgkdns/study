#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool ans = false;
int N, K, v[200005][2];
string P[2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> P[0];
	cin >> P[1];
	memset(v, -1, sizeof(v));
	queue<pair<int, bool>> q;
	q.push({ 0, 0 });
	v[0][0] = 0;
	while (!q.empty())
	{
		int here = q.front().first;
		bool p = q.front().second;
		q.pop();
		if (here >= N)
		{
			ans = true;
			break;
		}
		int t = v[here][p];
		if (here - 1 > t && v[here - 1][p] < 0 && P[p][here - 1] - '0')
		{
			v[here - 1][p] = t + 1;
			q.push({ here - 1, p });
		}
		if (v[here + 1][p] < 0 && (here > N || P[p][here + 1] - '0'))
		{
			v[here + 1][p] = t + 1;
			q.push({ here + 1, p });
		}
		if (v[here + K][!p] < 0 && (here + K > N || P[!p][here + K] - '0'))
		{
			v[here + K][!p] = t + 1;
			q.push({ here + K, !p });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15558