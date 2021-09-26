#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, num;
	priority_queue<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(-num);
	}
	int ans = 0;
	while (pq.size() > 1)
	{
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		pq.push(n1 + n2);
		ans -= (n1 + n2);
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1715