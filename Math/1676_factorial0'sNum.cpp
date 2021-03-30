#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int minFactor[501];
stack<int> s;

int main()
{
	int n, ans = 0; cin >> n;
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i < 501; i++) minFactor[i] = i;
	int sqrtn = int(sqrt(501));
	for (int i = 2; i <= sqrtn; i++)
		if (minFactor[i] == i)
			for (int j = i * i; j < 501; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;
	for (int cp = 2; cp <= n; cp++)
	{
		int tmp = cp;
		while (tmp > 1)
		{
			if (minFactor[tmp] == 2)
			{
				if (s.empty() || s.top() == 2)
					s.push(2);
				else
				{
					s.pop();
					ans++;
				}
			}
			else if (minFactor[tmp] == 5)
			{
				if (s.empty() || s.top() == 5)
					s.push(5);
				else
				{
					s.pop();
					ans++;
				}
			}
			tmp /= minFactor[tmp];
		}
	}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/1676

/*
maybe its easy but I solved it little hard way.
*/