#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<bool> isPrime;
queue<int> q;
int n, s = 0, ans = 0;
int main()
{
	cin >> n;
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (!isPrime[i]) continue;
		q.push(i);
		s += i;
		while (s > n && !q.empty())
		{
			s -= q.front();
			q.pop();
		}
		if (s == n) ans++;
	}
	if (n == 2) ans = 1;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1644

/*
queue is useful to solve this problem.
*/