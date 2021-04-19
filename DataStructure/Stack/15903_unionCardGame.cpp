#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
using ll = long long;

int main()
{
	int n, m, tmp;
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll s = 0;
	for (int c = 0; c < n; c++)
	{
		cin >> tmp;
		pq.push(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		ll c1 = pq.top();
		pq.pop();
		ll c2 = pq.top();
		pq.pop();
		ll c3 = c2 + c1;
		pq.push(c3);
		pq.push(c3);
	}

	while (!pq.empty())
	{
		s += pq.top();
		pq.pop();
	}

	cout << s << '\n';
}

// https://www.acmicpc.net/problem/15903