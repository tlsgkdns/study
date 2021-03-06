#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double getPPI(int w, int h)
{
	return sqrt(w * w + h * h) / 77;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<double, int>> ans;
	for (int i = 1; i <= n; i++)
	{
		int w, h;
		cin >> w >> h;
		ans.push_back({ -getPPI(w, h), i });
	}
	sort(ans.begin(), ans.end());
	for (pair<double, int> a : ans)
		cout << a.second << '\n';
}

// https://www.acmicpc.net/problem/20949

/*
Chose easy one, to rest from very difficult problem.
*/