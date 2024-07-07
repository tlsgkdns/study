#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool v[1000001];
int C, K, P;

priority_queue<pair<int, int>> pq1, pq2;
void popQueue(priority_queue<pair<int, int>>& pq)
{
	while (!pq.empty() && v[pq.top().second]) pq.pop();
	if (pq.empty()) cout << 0 << '\n';
	else
	{
		int now = pq.top().second;
		cout << now << '\n';
		v[now] = true;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> C;
		if (C == 0) break;
		if (C == 1)
		{
			cin >> K >> P;
			pq1.push({ P, K });
			pq2.push({ -P, K });
			v[K] = false;
		}
		if (C == 2)
		{
			popQueue(pq1);
		}
		if (C == 3)
		{
			popQueue(pq2);
		}
	}
}

// https://www.acmicpc.net/problem/3755