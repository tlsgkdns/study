#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int v[200001];
int N, K;
int main()
{
	memset(v, -1, sizeof(v));
	deque<int> dq;
	cin >> N >> K;
	dq.push_back(N);
	v[N] = 0;
	while (!dq.empty())
	{
		int now = dq.front();
		dq.pop_front();
		if (now == K) break;
		int next = now * 2;
		if (next <= 200000 && v[next] == -1)
		{
			v[next] = v[now];
			dq.push_front(next);
		}
		next = now + 1;
		if (next <= 100000 && v[next] == -1)
		{
			v[next] = v[now] + 1;
			dq.push_back(next);
		}
		next = now - 1;
		if (next >= 0 && v[next] == -1)
		{
			v[next] = v[now] + 1;
			dq.push_back(next);
		}

	}
	cout << v[K] << '\n';
}

// https://www.acmicpc.net/problem/13549