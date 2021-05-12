#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a = -1, b = -1;
	vector<int> ans;
	while (a != 0 || b != 0)
	{
		cin >> a >> b;
		ans.push_back(a + b);
	}
	ans.pop_back();
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/10952