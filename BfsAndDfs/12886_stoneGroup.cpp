#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

const int lim = 1500;
vector<vector<bool>> v(lim + 1, vector<bool>(lim + 1, false));
int A, B, C;
int main()
{
	cin >> A >> B >> C;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(A, B, C));
	v[A][B] = true;
	int ans = 0;
	if (((A + B + C) % 3) == 0)
	{
		while (!q.empty())
		{
			int a = get<0>(q.front());
			int b = get<1>(q.front());
			int c = get<2>(q.front());
			q.pop();
			if (a == b && b == c)
			{
				ans = 1;
				break;
			}
			if (a <= b && 2 * a <= lim && !v[2 * a][b - a])
			{
				v[2 * a][b - a] = true;
				q.push(make_tuple(2 * a, b - a, c));
			}
			if (b <= a && 2 * b <= lim && !v[a - b][2 * b])
			{
				v[a - b][2 * b] = true;
				q.push(make_tuple(a - b, 2 * b, c));
			}
			if (c <= b && 2 * c <= lim && !v[a][b - c])
			{
				v[a][b - c] = true;
				q.push(make_tuple(a, b - c, 2 * c));
			}
			if (b <= c && 2 * b <= lim && !v[a][2 * b])
			{
				v[a][2 * b] = true;
				q.push(make_tuple(a, 2 * b, c - b));
			}
			if (c <= a && 2 * c <= lim && !v[a - c][b])
			{
				v[a - c][b] = true;
				q.push(make_tuple(a - c, b, 2 * c));
			}
			if (a <= c && 2 * a <= lim && !v[2 * a][b])
			{
				v[2 * a][b] = true;
				q.push(make_tuple(2 * a, b, c - a));
			}
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/12886