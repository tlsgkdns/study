#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>>arr;
int N, P, D, ans = 0;
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> D;
		arr.push_back({ D, P });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		int d = arr[i].first;
		int c = arr[i].second;
		pq.push(-c);
		while (pq.size() > d)
			pq.pop();
	}
	while (!pq.empty())
	{
		ans -= pq.top();
		pq.pop();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2109