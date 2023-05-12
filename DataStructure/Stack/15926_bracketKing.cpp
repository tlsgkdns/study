#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int N, ans = 0, P[200001];
string str;
int main()
{
	memset(P, -1, sizeof(P));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	stack<int> s;
	cin >> N; cin >> str;
	for (int i = 0; i < N; i++)
	{
		if (str[i] == ')')
		{
			if (s.empty()) continue;
			int pos = s.top();
			s.pop();
			P[pos] = i;
		}
		else
			s.push(i);
	}
	int idx = 0, S = 0;
	while (idx < N)
	{
		if (P[idx] < 0)
		{
			S = 0;
			++idx;
			continue;
		}
		else
		{
			S += P[idx] - idx + 1;
			idx = P[idx] + 1;
			ans = max(ans, S);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15926