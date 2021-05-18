#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> truck;
queue<pair<int, int>> bridge;
int n, w, L, cnt = 1, time = 1, weight = 0;
int main()
{
	cin >> n >> w >> L;
	truck.resize(n);
	for (int i = 0; i < n; i++)
		cin >> truck[i];
	bridge.push({ truck[0], 0 });
	weight = truck[0];
	while (!bridge.empty())
	{
		time++;
		int s = bridge.size();
		for (int i = 0; i < s; i++)
		{
			pair<int, int> p = bridge.front();
			bridge.pop();
			p.second++;
			if (p.second == w)
				weight -= p.first;
			else
				bridge.push(p);
		}
		if (cnt < n && weight + truck[cnt] <= L)
		{
			weight += truck[cnt];
			bridge.push({ truck[cnt], 0 });
			cnt++;
		}
	}
	cout << time << '\n';
}

// https://www.acmicpc.net/problem/13335