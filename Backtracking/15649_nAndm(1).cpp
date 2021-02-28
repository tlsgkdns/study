#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void perm(int n, int m, vector<int> v, vector<bool> used, int depth)
{
	if (depth == m)
	{
		copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
		cout << '\n';
	}

	for (int next = 1; next <= n; next++)
	{
		if (used[next]) continue;
		used[next] = true;
		v.push_back(next);
		perm(n, m, v, used, depth + 1);
		used[next] = false;
		v.pop_back();
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> ns;
	vector<bool> used(n + 1, false);


	perm(n, m, ns, used, 0);
}
// https://www.acmicpc.net/problem/15649

/*
standard backtracking problem
*/