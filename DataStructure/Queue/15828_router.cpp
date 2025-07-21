#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int N, A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (true)
	{
		cin >> A;
		if (A < 0) break;
		if (A == 0) q.pop();
		else
		{
			if (q.size() == N) continue;
			q.push(A);
		}
	}
	if (q.empty()) cout << "empty\n";
	else
	{
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/15828