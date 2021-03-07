#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> ans;
	int n, first, second;
	cin >> n;
	first = n;
	for (int i = 1; i <= n; i++)
	{
		queue<int> q; int cnt = 2;
		first = n; second = i;
		q.push(first); q.push(second);
		while (true)
		{
			int tmp = first;
			first = second;
			second = tmp - second;
			if (second < 0) break;
			cnt++;
			q.push(second);
		}
		if (cnt > ans.size()) ans = q;
	}
	cout << ans.size() << '\n';
	while (!ans.empty()) { cout << ans.front() << " "; ans.pop(); };
}

// https://www.acmicpc.net/problem/2635

/*
Easy bruteforce problem. rest time.
*/