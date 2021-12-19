#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 1; n <= N; n++)
		q.push(n);
	while (q.size() != 1)
	{
		q.pop();
		if (q.size() == 1) break;
		int f = q.front();
		q.pop();
		q.push(f);
	}
	cout << q.front() << '\n';
}

// https://www.acmicpc.net/problem/2164