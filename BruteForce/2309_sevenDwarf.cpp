#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool v[9], solved = false;
int h[9];
vector<int> ans;
void getDwarf(int sum)
{
	if (solved) return;
	if (ans.size() == 7)
	{
		if (sum == 100)
			solved = true;
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		ans.push_back(h[i]);
		getDwarf(sum + h[i]);
		if (solved) return;
		v[i] = false;
		ans.pop_back();
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> h[i];
		v[i] = false;
	}
	getDwarf(0);
	sort(ans.begin(), ans.end());
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/2309