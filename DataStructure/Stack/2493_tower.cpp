#include <iostream>
#include <stack>

using namespace std;
using pii = pair<int, int>;
int tower[500001], ans[500001];
int N, T;
stack<pii> l, r;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T;
		l.push({ T, i });
	}
	while (!l.empty())
	{
		if (r.empty())
		{
			r.push(l.top());
			l.pop();
		}
		while (!l.empty() && l.top().first < r.top().first)
		{
			r.push(l.top());
			l.pop();
		}
		if (l.empty()) break;
		while (!r.empty() && r.top().first < l.top().first)
		{
			ans[r.top().second] = l.top().second;
			r.pop();
		}
	}
	while (!r.empty())
	{
		ans[r.top().second] = 0;
		r.pop();
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2493