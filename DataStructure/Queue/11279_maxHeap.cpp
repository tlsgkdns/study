#include <iostream>
#include <queue>
using namespace std;

int N, x;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int> pq;
	vector<int> ans;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty()) pq.push(0);
			ans.push_back(pq.top());
			pq.pop();
		}
		else pq.push(x);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/11279