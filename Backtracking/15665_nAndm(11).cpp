#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tmp, num;
int N, M, A[10], cnt[11];
void solve(int d)
{
	if (d == M)
	{
		for (int i = 0; i < tmp.size(); i++)
			cout << tmp[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < num.size(); i++)
	{
		tmp.push_back(num[i]);
		solve(d + 1);
		tmp.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (cnt[A[i]] == 0)
			num.push_back(A[i]);
		++cnt[A[i]];
	}
	sort(num.begin(), num.end());
	solve(0);
}

// https://www.acmicpc.net/problem/15665