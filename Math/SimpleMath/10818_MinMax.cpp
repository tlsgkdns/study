#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, num, mn = 1000001, mx = -1000001;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		mn = min(mn, num);
		mx = max(mx, num);
	}
	cout << mn << " " << mx << '\n';
}

//https://www.acmicpc.net/problem/10818