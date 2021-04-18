#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	vector<long long> out;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	long long n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0)
		{
			if (q.empty()) out.push_back(num);
			else { out.push_back(q.top()); q.pop(); }
		}
		else
			q.push(num);
	}

	for (int o : out) cout << o << '\n';
}

// https://www.acmicpc.net/problem/1927