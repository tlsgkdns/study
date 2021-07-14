#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> tile;
vector<int> e, ans;
int N, a, b, s = 0, dst;

bool isEnd(int num)
{
	for (int i = 1; i < e.size(); i++)
		if (e[i] == num) return true;
	return false;
}
bool isFirst(int num)
{
	for (int i = 0; i < e.size() - 1; i++)
		if (e[i] + 1 == num) return true;
	return false;
}
bool isTop(int num)
{
	if (num > e[0] && num <= e[1]) return true;
	return false;
}
bool isBottom(int num)
{
	if (num > e[N - 1] && num <= e[N]) return true;
	return false;
}
int getRightUp(int num)
{
	return num - (N - 1);
}
int getRightDown(int num)
{
	return num + N;
}
int getLeftUp(int num)
{
	return num - N;
}
int getLeftDown(int num)
{
	return num + (N - 1);
}

bool isLeftEmpty(int num)
{
	return ((num - 1) % (2 * N - 1) == 0);
}
bool isRightEmpty(int num)
{
	return ((num >= N) && ((num - N) % (2 * N - 1) == 0));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	ans.push_back(-1);
	tile.push_back({ 0, 0 });
	dst = (N * N) - (N / 2);
	for (int i = 0; i < dst; i++)
	{
		cin >> a >> b;
		tile.push_back({ a, b });
	}
	bool f = true;
	for (int i = 0; i <= N; i++)
	{
		e.push_back(s);
		if (f) s += N;
		else s += (N - 1);
		f = !f;
	}
	queue<vector<int>> q;
	q.push(vector<int>{1});
	vector<bool> v(dst + 1, false);
	v[1] = true;
	while (!q.empty())
	{
		vector<int> route = q.front();
		q.pop();
		int cur = route.back();

		if (cur == dst)
		{
			ans = route;
			break;
		}
		else if (ans.back() < cur)
			ans = route;
		if (!isEnd(cur) && tile[cur + 1].first == tile[cur].second && !v[cur + 1])
		{
			v[cur + 1] = true;
			route.push_back(cur + 1);
			q.push(route);
			route.pop_back();
		}
		if (!isFirst(cur) && tile[cur - 1].second == tile[cur].first && !v[cur - 1])
		{
			v[cur - 1] = true;
			route.push_back(cur - 1);
			q.push(route);
			route.pop_back();
		}
		if (!isTop(cur))
		{
			if (!isRightEmpty(cur) && tile[getRightUp(cur)].first == tile[cur].second && !v[getRightUp(cur)])
			{
				v[getRightUp(cur)] = true;
				route.push_back(getRightUp(cur));
				q.push(route);
				route.pop_back();
			}
			if (!isLeftEmpty(cur) && tile[getLeftUp(cur)].second == tile[cur].first && !v[getLeftUp(cur)])
			{
				v[getLeftUp(cur)] = true;
				route.push_back(getLeftUp(cur));
				q.push(route);
				route.pop_back();
			}
		}
		if (!isBottom(cur))
		{
			if (!isRightEmpty(cur) && tile[getRightDown(cur)].first == tile[cur].second && !v[getRightDown(cur)])
			{
				v[getRightDown(cur)] = true;
				route.push_back(getRightDown(cur));
				q.push(route);
				route.pop_back();
			}
			if (!isLeftEmpty(cur) && tile[getLeftDown(cur)].second == tile[cur].first && !v[getLeftDown(cur)])
			{
				v[getLeftDown(cur)] = true;
				route.push_back(getLeftDown(cur));
				q.push(route);
				route.pop_back();
			}
		}

	}
	cout << ans.size() << '\n';
	for (int a : ans) cout << a << " ";
	cout << '\n';
}
// https://www.acmicpc.net/problem/5213