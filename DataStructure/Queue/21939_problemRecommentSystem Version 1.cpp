#include <iostream>
#include <queue>
using namespace std;

string cmd;
int N, L, X, P, M, D[100001];
struct cmp1
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.second == p2.second) return p1.first < p2.first;
		return p1.second < p2.second;
	}
};
struct cmp2
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.second == p2.second) return p1.first > p2.first;
		return p1.second > p2.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> L;
		pq1.push({ P, L });
		pq2.push({ P, L });
		D[P] = L;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			cin >> P >> L;
			D[P] = L;
			pq1.push({ P, L });
			pq2.push({ P, L });
		}
		if (cmd == "recommend")
		{
			cin >> X;
			if (X < 0)
			{
				while (!pq2.empty() && D[pq2.top().first] != pq2.top().second) pq2.pop();
				cout << pq2.top().first << '\n';
			}
			else
			{
				while (!pq1.empty() && D[pq1.top().first] != pq1.top().second) pq1.pop();
				cout << pq1.top().first << '\n';
			}
		}
		if (cmd == "solved")
		{
			cin >> P;
			D[P] = -1;
		}
	}
}

// https://www.acmicpc.net/problem/21939