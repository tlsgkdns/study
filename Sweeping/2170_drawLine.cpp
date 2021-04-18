#include <iostream>
#include <vector>
#include <algorithm>
#define INF -1000000000
using namespace std;

vector<pair<int, int>> line;
int n, a;
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n; line.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> line[i].first >> line[i].second;
		if (line[i].first > line[i].second) swap(line[i].first, line[i].second);
	}
	sort(line.begin(), line.end());
	int f = INF, s = INF;
	for (int i=0; i < n; i++)
	{
		if (line[i].second <= s && line[i].first >= f) continue;
		if (s < line[i].first)
		{
			a += s - f;
			f = line[i].first;
			s = line[i].second;
		}
		else
			s = max(s, line[i].second);
	}
	a += s - f;
	cout << a << '\n';
}

// https://www.acmicpc.net/problem/2170