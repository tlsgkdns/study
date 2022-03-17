#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int N, x1, yy1, x2, y2, x3, y3, x4, y4;

vector<string> ans;
vector<pair<double, double>> p;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		string res = "";
		if ((y2 - yy1) * (x4 - x3) != (y4 - y3) * (x2 - x1))
		{
			res = "POINT ";
			double t = 1. * ((y4 - y3) * (x1 - x3) - (x4 - x3) * (yy1 - y3)) /
				((y2 - yy1) * (x4 - x3) - (x2 - x1) * (y4 - y3));
			double x = (x2 - x1) * t + x1; double y = (y2 - yy1) * t + yy1;
			p.push_back({ x, y });
		}
		else
		{
			if (y3 * (x1 - x2) == (yy1 - y2) * (x3 - x1) + yy1 * (x1 - x2))
				res = "LINE";
			else
				res = "NONE";
		}
		ans.push_back(res);
	}
	int idx = 0;
	for (int i = 0; i < N; i++)
	{

		cout << ans[i];
		if (ans[i] == "POINT ")
		{
			cout << fixed << setprecision(2) << p[idx].first << " " << p[idx].second;
			idx++;
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/6487