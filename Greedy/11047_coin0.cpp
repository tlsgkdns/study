#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, index, ans = 0, sum = 0;
	cin >> n >> k;
	vector<int> coin;
	index = n - 1;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}

	while (sum != k)
	{
		if ((coin[index] + sum) > k) { index--; continue; }
		sum += coin[index];
		ans++;
	}

	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11047