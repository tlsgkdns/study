#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> input, H, W;
int N, X, Y;

int solve(vector<pair<int, int>>& pos)
{
	sort(pos.begin(), pos.end());
	priority_queue<int> pq;
	int ret = 0;
	for (int i = 0; i < pos.size(); i++)
	{
		int a = pos[i].first;
		int b = pos[i].second;
		while (!pq.empty() && pq.top() <= a) pq.pop();
		pq.push(b);
		ret = max(ret, (int)pq.size());
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		input.push_back({ X, Y });
	}
	input.push_back(input[0]);
	for (int i = 0; i < N; i++)
	{
		if (input[i].first == input[i + 1].first)
		{
			int a = input[i].second;
			int b = input[i + 1].second;
			if (a > b) swap(a, b);
			H.push_back({ a, b });
		}
		if (input[i].second == input[i + 1].second)
		{
			int a = input[i].first;
			int b = input[i + 1].first;
			if (a > b) swap(a, b);
			W.push_back({ a, b });
		}
	}
	cout << max(solve(H), solve(W)) << '\n';
}

// https://www.acmicpc.net/problem/17611