#include <iostream>
#include <queue>

using namespace std;

string cmd;
vector<int> ans;
queue<int> q;
int N, E;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> E;
			q.push(E);
		}
		if (cmd == "front")
			ans.push_back((q.empty() ? -1 : q.front()));
		if (cmd == "back")
			ans.push_back((q.empty() ? -1 : q.back()));
		if (cmd == "size")
			ans.push_back((q.size()));
		if (cmd == "pop")
		{
			if (q.empty()) ans.push_back(-1);
			else
			{
				ans.push_back(q.front());
				q.pop();
			}
		}
		if (cmd == "empty")
			ans.push_back(q.empty());
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/18258