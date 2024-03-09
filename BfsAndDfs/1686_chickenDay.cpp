#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

vector<double> X, Y;
int V, M, v[1001];
double xs, ys, xt, yt, x, y, T = 0;

double getDist(int idx1, int idx2)
{
	return sqrt(pow(X[idx1] - X[idx2], 2) + pow(Y[idx1] - Y[idx2], 2));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> V >> M;
	T = V * 60 * M;
	cin >> xs >> ys >> xt >> yt;
	X.push_back(xs); Y.push_back(ys);
	X.push_back(xt); Y.push_back(yt);
	while (true)
	{
		cin >> x >> y;
		if (cin.eof()) break;
		X.push_back(x);
		Y.push_back(y);
	}
	queue<int> q;
	q.push(0);
	v[0] = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < X.size(); i++)
		{
			if (v[i] >= 0 || getDist(now, i) >= T) continue;
			v[i] = v[now] + 1;
			q.push(i);
		}
	}
	if (v[1] < 0) cout << "No.\n";
	else cout << "Yes, visiting " << v[1] - 1 << " other holes.\n";
}

// https://www.acmicpc.net/problem/1686