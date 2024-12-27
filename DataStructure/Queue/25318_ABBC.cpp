#include <iostream>
#include <queue>

using namespace std;

string S;
bool v[300001];
queue<int> q;
int ans = 0, cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'B') q.push(i);
		if (S[i] == 'C' && !q.empty())
		{
			v[q.front()] = true;
			++ans;
			q.pop();
		}
	}
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'A') ++cnt;
		if (v[i]) continue;
		if (S[i] == 'B' && cnt > 0)
		{
			--cnt;
			++ans;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25381