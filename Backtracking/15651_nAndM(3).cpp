#include <iostream>
#include <vector>
using namespace std;
vector<int> v, pr;
int n, m;
void nAndM(int num)
{
	if (num == m)
	{
		for (int p : pr) cout << p << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		pr.push_back(i);
		nAndM(num + 1);
		pr.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	nAndM(0);
}
// https://www.acmicpc.net/problem/15651

/*
standard backtracking problem.
*/