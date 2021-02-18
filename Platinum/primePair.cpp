#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <list>

using namespace std;

vector<bool> isPrime(2001, true), check;
vector<int> arr, ans, p;
vector<list<int>> adj;

bool dfs(int x)
{
	if (check[x]) return false;
	check[x] = true;

	for (int e : adj[x])
	{
		if (p[e] == -1 || dfs(p[e]))
		{
			p[e] = x;
			return true;
		}
	}

	return false;
}

void makeGraph(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i != j && isPrime[arr[i] + arr[j]])
				adj[i].push_back(j);
		}
}
int main()
{
	int n, od = 0, ev = 0;
	cin >> n;

	arr.resize(n);
	adj.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] % 2 == 1) od++;
		else ev++;
	}

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < sqrt(2001); i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i + i; j < 2001; j += i)
		{
			isPrime[j] = false;
		}
	}
	makeGraph(n);

	for (int el : adj[0])
	{
		if (od != ev) break;
		p.clear();
		p.resize(n, -1);
		p[el] = 0;
		bool flag = true;
		for (int j = 1; j < n; j++)
		{
			check.clear();
			check.resize(n, false);
			check[0] = true;
			if (!dfs(j))
			{
				flag = false;
				break;
			}
		}
		if (flag) ans.push_back(arr[el]);
	}

	sort(ans.begin(), ans.end());

	if (ans.empty()) cout << -1 << endl;
	else copy(ans.begin(), ans.end(), ostream_iterator<int>{cout, " "});

	return 0;
}

// problem: https://www.acmicpc.net/problem/1017

/*
eratosthenes + Bipartite match
I haven't seen Bipartite matching. so I googled it
and apply that algorithm.
For the first time, I used adjacent matrix, 
but scoring program said it's incorrect.
So I changed adjacent list, then it said correct
Maybe adjacent list can be useful than I thought
*/