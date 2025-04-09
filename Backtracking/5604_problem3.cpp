#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> r;
int N;

void solve(int n, int s)
{
	if (n == 0)
	{
		for (int i = 0; i < r.size() - 1; i++) cout << r[i] << " ";
		cout << r.back() << '\n';
		return;
	}
	for (int i = min(n, s); i > 0; i--)
	{
		r.push_back(i);
		solve(n - i, i);
		r.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	solve(N, N);
}

// https://www.acmicpc.net/problem/5604