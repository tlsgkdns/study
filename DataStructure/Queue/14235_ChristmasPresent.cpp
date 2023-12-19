#include <iostream>
#include <queue>

using namespace std;
int N, A, G;
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> A;
		if (A == 0)
		{
			if (pq.empty()) cout << -1 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			for (int a = 0; a < A; a++)
			{
				cin >> G;
				pq.push(G);
			}
		}
	}
}

// https://www.acmicpc.net/problem/14235