#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, wait = 0, ans = 0;
	cin >> n;
	vector<int> line(n);
	for (int i = 0; i < n; i++)
		cin >> line[i];
	sort(line.begin(), line.end());
	for (int i = 0; i < n; i++)
	{
		wait += line[i];
		ans += wait;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11399