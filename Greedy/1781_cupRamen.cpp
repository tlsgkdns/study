#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
bool v[200001];
int N, A, B, t = 1, ans = 0;
pii arr[200001];
priority_queue<int> pq;
bool cmp(pii p1, pii p2)
{
	if (p1.first == p2.first) return p1.second > p2.second;
	return p1.first < p2.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		if (t <= arr[i].first)
		{
			pq.push(-arr[i].second);
			++t;
		}
		else if (-pq.top() < arr[i].second)
		{
			pq.pop();
			pq.push(-arr[i].second);
		}
	}
	while (!pq.empty())
	{
		ans -= pq.top();
		pq.pop();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1781