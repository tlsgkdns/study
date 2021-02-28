#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	vector<int> dp(n);
	vector<int> arr(n);
	bool cont = true;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	m = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (i == 0) dp[i] = arr[i];
		else
		{
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			m = max(m, dp[i]);
		}
	}
	cout << m << '\n';
}

//https://www.acmicpc.net/problem/1912

/*
I had seen this problem on book, but I didn't remember
But, I solved it myself.
*/