#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int A, K, v[1000001];

queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> A >> K;
	q.push(A);
	v[A] = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now + 1 <= K && v[now + 1] < 0)
		{
			v[now + 1] = v[now] + 1;
			q.push(now + 1);
		}
		if (2 * now <= K && v[2 * now] < 0)
		{
			v[2 * now] = v[now] + 1;
			q.push(2 * now);
		}
	}
	cout << v[K] << '\n';
}

// https://www.acmicpc.net/problem/25418