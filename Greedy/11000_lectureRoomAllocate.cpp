#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, S, T;
vector<pair<int, int>> arr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> T;
		arr.push_back({ S, T });
	}
	sort(arr.begin(), arr.end());
	priority_queue<int> pq;
	pq.push(0);
	for (int i = 0; i < N; i++)
	{
		if (-pq.top() <= arr[i].first)
			pq.pop();
		pq.push(-arr[i].second);
	}
	cout << (int)pq.size() << '\n';
}

// https://www.acmicpc.net/problem/11000