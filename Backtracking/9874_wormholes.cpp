#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> hole;
vector<int> conn;
int N, ans = 0;
bool isThereCycle()
{
	for (int start = 0; start < N; start++)
	{
		vector<bool> v(N, false);
		v[start] = true;
		int now = conn[start];
		while (true)
		{
			int next = -1;
			for (int i = 0; i < N; i++)
				if (hole[now].second == hole[i].second && hole[now].first < hole[i].first)
					if (next == -1 || hole[next].first > hole[i].first)
						next = i;
			if (next == -1)
			{
				now = next;
				break;
			}
			if (v[next]) return true;
			v[next] = true;
			now = conn[next];
		}
		if (now != -1) return true;
	}
	return false;
}

void brute(int idx)
{
	if (idx == N)
	{
		if (isThereCycle())
			ans++;
		return;
	}
	if (conn[idx] != -1)
	{
		brute(idx + 1);
		return;
	}
	for (int i = idx + 1; i < N; i++)
	{
		if (conn[i] != -1 || idx == i) continue;
		conn[idx] = i;
		conn[i] = idx;
		brute(idx + 1);
		conn[idx] = -1;
		conn[i] = -1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	conn.resize(N, -1); hole.resize(N);
	for (int i = 0; i < N; i++)
		cin >> hole[i].first >> hole[i].second;
	brute(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/9874