#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T, A, B, ans = 0;
vector<vector<bool>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T >> A >> B;
	queue<pair<int, bool>> q;
	q.push({ A, false }); q.push({ B, false });
	v.resize(T + 1, vector<bool>(2, false));
	while (!q.empty())
	{
		int full = q.front().first;
		bool water = q.front().second;
		q.pop();
		ans = max(ans, full);
		if (full + A <= T && !v[full + A][water])
		{
			v[full + A][water] = true;
			q.push({ full + A, water });
		}
		if (full + B <= T && !v[full + B][water])
		{
			v[full + B][water] = true;
			q.push({ full + B, water });
		}
		if (!water && !v[full / 2][true])
		{
			v[full / 2][true] = true;
			q.push({ full / 2, true });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11964