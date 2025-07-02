#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int N;
bool f = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	while (!q.empty())
	{
		if (!f)
			cout << q.front() << " ";
		else
			q.push(q.front());
		q.pop();
		f = !f;
	}
}

// https://www.acmicpc.net/problem/2161