#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100002

using namespace std;

int change(int money)
{
	if (money == 1) return INF;
	if (money < 5)
	{
		if (money % 2 == 0)
			return money / 2;
		else
			return INF;
	}
	if (money % 5 == 0)
		return money / 5;

	if (money % 2 == 0)
		return min(change(money - 5) + 1, money / 2);

	return change(money - 5) + 1;
}
int main()
{
	int n;
	cin >> n;

	int tmp = change(n);
	int ans = ((tmp == INF) ? -1 : tmp);
	cout << ans << endl;
}

// https://www.acmicpc.net/problem/14916