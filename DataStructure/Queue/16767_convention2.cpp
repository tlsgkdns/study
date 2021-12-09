#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, a, t;
priority_queue<pair<int, int>> pq;
queue<pair<int, int>> buf;
vector<int> times;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	times.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a >> times[i];
		pq.push({ -a, i });
	}
	int cow = 0, time = 0, delay = 0;
	while (cow < N)
	{
		int arrive, num = N;
		while (!pq.empty() && -pq.top().first < time)
		{
			int ar = -pq.top().first;
			int n = pq.top().second;
			pq.pop();
			if (num > n)
			{
				if (num != N) buf.push({ -arrive, num });
				arrive = ar; num = n;
			}
			else
			{
				buf.push({ -ar, n });
			}
		}
		if (num == N)
		{
			arrive = -pq.top().first;
			num = pq.top().second;
			pq.pop();
		}
		else
		{
			while (!buf.empty())
			{
				pq.push(buf.front());
				buf.pop();
			}
		}
		if (arrive > time)
			time = arrive;
		else
			delay = max(delay, time - arrive);
		cow++;
		time += times[num];
	}
	cout << delay << '\n';
}

// https://www.acmicpc.net/problem/16767