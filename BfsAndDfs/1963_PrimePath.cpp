#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> isPrime(10001, true);

int change(int num, int d, int to)
{
	if (d == 3 && to == 0) return -1;
	int digit = pow(10, d);
	int dnum = digit * to;
	int ret = 0;
	for (int i = 3; i >= 0; i--)
	{
		int t = pow(10, i);
		int tmp = (num / t) * t;
		num -= tmp;
		if (d == i) continue;
		ret += tmp;
	}

	ret += dnum;
	return ret;
}
int main()
{
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= 101; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j < 10001; j += i)
			isPrime[j] = false;
	}

	int n;
	cin >> n;
	vector<int> ans(n, -1);

	for (int i = 0; i < n; i++)
	{
		int src, dst;
		vector<bool> visited(10001, false);
		cin >> src >> dst;
		queue<pair<int, int>> q;
		q.push(make_pair(src, 0));
		while (!q.empty())
		{
			int num = q.front().first;
			int cnt = q.front().second;
			if (num == dst) { ans[i] = cnt; break; }
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				for (int c = 0; c <= 9; c++)
				{
					int tmp = change(num, d, c);
					if (tmp == -1 || !isPrime[tmp] || visited[tmp]) continue;
					q.push(make_pair(tmp, cnt + 1));
					visited[tmp] = true;
				}
			}
		}
	}

	for (int a : ans)
		if (a == -1) cout << "Impossible" << '\n';
		else cout << a << endl;

	return 0;
}

// https://www.acmicpc.net/problem/1963