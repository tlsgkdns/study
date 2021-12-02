#include <iostream>
#include <stack>
using namespace std;

stack<char> l, r;
string str, ans = "";
int M, t;
char cmd, ch;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (char c : str) l.push(c);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> ch;
			l.push(ch);
		}
		if (cmd == 'L' && !l.empty())
		{
			r.push(l.top());
			l.pop();
		}
		if (cmd == 'D' && !r.empty())
		{
			l.push(r.top());
			r.pop();
		}
		if (cmd == 'B' && !l.empty())
			l.pop();

	}
	while (!l.empty())
	{
		r.push(l.top());
		l.pop();
	}
	while (!r.empty())
	{
		ans.push_back(r.top());
		r.pop();
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1406