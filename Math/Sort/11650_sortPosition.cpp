#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end());
	for (auto e : p) cout << e.first << " " << e.second << '\n';
}

// https://www.acmicpc.net/problem/11650

/*
sort pair
*/