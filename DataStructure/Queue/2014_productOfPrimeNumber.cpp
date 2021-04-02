#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
unordered_map<long long, bool> mp;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, n; long long mx = 0;
	cin >> k >> n;
	vector<long long> prime(k);
	for (int i = 0; i < k; i++)
	{
		cin >> prime[i];
		pq.push(prime[i]);
		mx = prime[i];
	}

	for (int i = n; i > 1; i--)
	{
		long long t = pq.top();
		pq.pop();
		for (int j = 0; j < k; j++)
		{
			long long nxt = t * prime[j];
			if (pq.size() > i&& mx < nxt) continue;

			if (mp.count(nxt) == 0)
			{
				mx = max(nxt, mx);
				pq.push(nxt);
				mp[nxt] = true;
			}
		}
	}
	cout << pq.top() << '\n';
}


/*
Difficult priority queue problem.
I almost coded myself, And searched what I have to insert to the queue.
I understood what I brought from another code.
*/