#include <iostream>
#include <queue>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> right;
	priority_queue<int, vector<int>, less<int>> left;
	vector<int> v, tmp;
	int n, num, cen;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (i == 0) left.push(num);
		else if (left.size() == right.size())
		{
			if (left.top() <= num)
			{
				right.push(num);
				left.push(right.top());
				right.pop();
			}
			else
				left.push(num);
		}
		else
		{
			if (left.top() >= num)
			{
				left.push(num);
				right.push(left.top());
				left.pop();
			}
			else
				right.push(num);
		}
		left; right;
		v.push_back(left.top());
	}

	for (int a : v) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1655

/*
max_heap + min_heap
problem of idea that using priority_queue
At First, used a max_heap and pushed one by one and poped one by one.
Only waiting for me was "Times out"
It was hard than my first thought.
*/