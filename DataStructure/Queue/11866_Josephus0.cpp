#include <queue>
#include <iostream>
using namespace std;
int main()
{
	queue<int> q, a;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		q.push(i + 1);
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		a.push(q.front());
		q.pop();
	}
	cout << "<";
	while (!a.empty())
	{
		cout << a.front();
		if (a.size() != 1)
			cout << ", ";
		else
			cout << ">" << '\n';
		a.pop();
	}
}

// https://www.acmicpc.net/problem/11866