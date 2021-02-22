#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> arr;
int m, n;

void dfs(vector<int> v, int start)
{
	if (v.size() == n)
	{
		for (int e : v)
			cout << e << " ";
		cout << endl;
		return;
	}

	for (int i = start; i < m; i++)
	{
		if (arr[i] == 0) continue;
		int num = arr[i];
		arr[i] = 0;
		v.push_back(num);
		dfs(v, i + 1);
		v.pop_back();
		arr[i] = num;
	}
}
int main()
{
	vector<int> v;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		arr.push_back(i);
	dfs(v, 0);
	return 0;
}

// https://www.acmicpc.net/problem/15650

/*
standard backtracking problem
*/