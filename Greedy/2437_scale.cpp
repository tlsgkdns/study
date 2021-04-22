#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, tmp, ans = 0;
vector<int> scale;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		scale.push_back(tmp);
	}
	sort(scale.begin(), scale.end());
	ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (ans < scale[i]) break;
		ans += scale[i];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2437