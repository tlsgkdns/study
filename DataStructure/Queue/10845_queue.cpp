#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N, num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	queue<int> q;
	cin >> N; string cmd;
	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop")
		{
			if (q.empty()) q.push(-1);
			ans.push_back(q.front());
			q.pop();
		}
		else if (cmd == "back")
			if (q.empty()) ans.push_back(-1);
			else ans.push_back(q.back());
		else if (cmd == "size")
			ans.push_back((int)q.size());
		else if (cmd == "front")
			if (q.empty()) ans.push_back(-1);
			else ans.push_back(q.front());
		else
			ans.push_back((int)q.empty());
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/10845