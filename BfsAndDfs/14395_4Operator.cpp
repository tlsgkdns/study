#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
using ll = long long;
queue<ll> q;
unordered_map<ll, string> D;
ll S, T;
string ans = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> T;
	D[S] = "";
	q.push(S);
	while (!q.empty())
	{
		ll here = q.front();
		q.pop();
		if (here == T)
		{
			ans = D[here];
			break;
		}
		ll nxt = here * here;
		if (nxt <= T && D.find(nxt) == D.end())
		{
			D[nxt] = D[here] + '*';
			q.push(nxt);
		}
		nxt = here + here;
		if (nxt <= T && D.find(nxt) == D.end())
		{
			D[nxt] = D[here] + '+';
			q.push(nxt);
		}
		if (D.find(0) == D.end())
		{
			D[0] = D[here] + '-';
			q.push(0);
		}
		if (D.find(1) == D.end())
		{
			D[1] = D[here] + '/';
			q.push(1);
		}
	}
	if (S == T) cout << 0 << '\n';
	else if (ans == "") cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14395