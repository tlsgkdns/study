#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int N, K, A, B, D = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> A >> B;
	for (int i = 0; i < N; i++) pq.push(-K);
	while (-pq.top() - D > 0)
	{
		for (int i = 0; i < A; i++)
		{
			int now = -pq.top();
			pq.pop();
			pq.push(-(now + B));
		}
		++D;
	}
	cout << D << '\n';
}

// https://www.acmicpc.net/problem/23351