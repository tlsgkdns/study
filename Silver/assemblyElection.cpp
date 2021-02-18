#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int tmp, t = 0, n, s = 0;
	cin >> n;
	priority_queue<int> vote;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (i == 0) { t = tmp; continue; }
		vote.push(tmp);
	}

	while (!vote.empty())
	{
		if (vote.top() < t) break;
		int f = vote.top() - 1;
		vote.pop(); t++; s++;
		vote.push(f);
	}

	cout << s << endl;
}

// https://www.acmicpc.net/problem/1417
/*
Unexpectedly, little difficult to thought
priority_queue + greedy
*/