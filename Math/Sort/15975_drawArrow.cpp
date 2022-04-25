#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001, INF = 1000000001;
int N, X, Y, L, R, S;
long long ans = 0;
vector<int> points[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		points[Y].push_back(X);
	}
	for (int i = 1; i <= N; i++)
		sort(points[i].begin(), points[i].end());
	for (int i = 1; i <= N; i++)
	{
		S = (int)points[i].size();
		if (S <= 1) continue;
		for (int j = 0; j < S; j++)
		{
			L = INF; R = INF;
			if (j > 0) L = points[i][j] - points[i][j - 1];
			if (j < S - 1) R = points[i][j + 1] - points[i][j];
			ans += min(L, R);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15975