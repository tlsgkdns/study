#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
ll M, T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		vector<ll> ans;
		cin >> M;
		priority_queue<ll> pq1, pq2;
		for (int i = 0; i < M; i++)
		{
			cin >> N;
			if (i == 0) pq1.push(N);
			else if (pq1.size() == pq2.size())
			{
				if (pq1.top() < N)
				{
					pq2.push(-N);
					pq1.push(-pq2.top());
					pq2.pop();
				}
				else
					pq1.push(N);
			}
			else
			{
				if (pq1.top() >= N)
				{
					pq1.push(N);
					pq2.push(-pq1.top());
					pq1.pop();
				}
				else
					pq2.push(-N);
			}
			if (i % 2 == 0)
				ans.push_back(pq1.top());
		}
		cout << ans.size();
		for (int i = 0; i < ans.size(); i++)
		{
			if (i % 10 == 0) cout << '\n';
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2696