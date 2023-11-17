#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
int N, cnt1 = 0, cnt2 = 0;
string S, L, ans = "Possible";
queue<string> q[103];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; cin.ignore();
	for (int i = 0; i < N + 1; i++)
	{
		getline(cin, S);
		istringstream ss(S);
		string tmp = "";
		while (getline(ss, tmp, ' '))
		{
			q[i].push(tmp);
			++cnt1;
		}
	}
	int s = q[N].size();
	for (int i = 0; i < s; i++)
	{
		string W = q[N].front();
		bool f = false;
		for (int idx = 0; idx < N; idx++)
		{
			if (!q[idx].empty() && q[idx].front() == W)
			{
				q[N].pop();
				q[idx].pop();
				f = true;
				break;
			}
		}
		if (!f) break;
	}
	for (int i = 0; i < N + 1; i++)
		if (!q[i].empty())
		{
			ans = "Impossible\n";
			break;
		}
	cout << ans;
}

// https://www.acmicpc.net/problem/14713