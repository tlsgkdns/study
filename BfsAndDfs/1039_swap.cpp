#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

string n, ans;
int k, s;
queue<pair<string, int>> q;
bool visited[1000001][11];

int main()
{
	cin >> n >> k;
	s = n.size(); ans = "-1";
	memset(visited, false, sizeof(visited));
	q.push({ n, 0 });
	while (!q.empty())
	{
		string str = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (str[0] == '0') continue;
		if (cnt == k)
		{
			if (stoi(str) > stoi(ans)) ans = str;
			continue;
		}
		if (visited[stoi(str)][cnt]) continue;
		visited[stoi(str)][cnt] = true;
		for (int i = 0; i < s; i++)
			for (int j = i + 1; j < s; j++)
			{
				string tmp = str;
				if (i == 0 && tmp[j] == '0') continue;
				swap(tmp[i], tmp[j]);
				q.push(make_pair(tmp, cnt + 1));
			}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1039