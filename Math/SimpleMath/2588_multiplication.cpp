#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, tmp;
	cin >> a >> b; tmp = b;
	vector<int> ans;
	while (tmp != 0)
	{
		int r = tmp % 10;
		ans.push_back(r * a);
		tmp /= 10;
	}
	for (int a : ans) cout << a << '\n';
	cout << a * b << '\n';
}

// https://www.acmicpc.net/problem/2588
/*
Simple math.
*/