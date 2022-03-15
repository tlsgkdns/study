#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int A, B, C, D, ans = -1;
map<pair<int, int>, int> um;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	um[{0, 0}] = 0;
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = um[{a, b}];
		q.pop();
		if (C == a && D == b)
		{
			ans = c;
			break;
		}
		if (um.count({ A, b }) == 0)
		{
			um[{A, b}] = c + 1;
			q.push({ A, b });
		}
		if (um.count({ a, B }) == 0)
		{
			um[{a, B}] = c + 1;
			q.push({ a, B });
		}
		if (um.count({ a, 0 }) == 0)
		{
			um[{a, 0}] = c + 1;
			q.push({ a, 0 });
		}
		if (um.count({ 0, b }) == 0)
		{
			um[{0, b}] = c + 1;
			q.push({ 0, b });
		}
		if (a <= (B - b) && um.count({ 0, a + b }) == 0)
		{
			um[{0, a + b}] = c + 1;
			q.push({ 0, a + b });
		}
		if (a > (B - b) && um.count({ a - (B - b), B }) == 0)
		{
			um[{a - (B - b), B}] = c + 1;
			q.push({ a - (B - b), B });
		}
		if (b <= (A - a) && um.count({ a + b, 0 }) == 0)
		{
			um[{a + b, 0}] = c + 1;
			q.push({ a + b, 0 });
		}
		if (b > (A - a) && um.count({ A, b - (A - a) }) == 0)
		{
			um[{ A, b - (A - a)}] = c + 1;
			q.push({ A, b - (A - a) });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14867