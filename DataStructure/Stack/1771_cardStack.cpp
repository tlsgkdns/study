#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

using namespace std;

stack<pair<pair<int, int>, int>> s;
int N, C[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	for (int i = 0; i < N; i++)
	{
		pair<int, int> now = { C[i], C[i] };
		while (!s.empty() && (s.top().first.second + 1 == now.first || s.top().first.first == now.second + 1))
		{
			cout << s.top().second << '\n';
			now = make_pair(min(s.top().first.first, now.first), max(s.top().first.second, now.second));
			s.pop();
		}
		s.push({ now, i + 1 });
	}
}

// https://www.acmicpc.net/problem/1771