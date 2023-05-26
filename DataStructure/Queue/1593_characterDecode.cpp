#include <iostream>
#include <queue>
#include <cctype>
using namespace std;

int w, s, ans = 0;
string W, S;
int alp1[53], alp2[53];
bool cmp()
{
	for (int i = 0; i < 53; i++)
		if (alp1[i] != alp2[i])
			return false;
	return true;
}
int getIndex(char c)
{
	if (isupper(c)) return c - 'A' + 26;
	return c - 'a';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> w >> s;
	cin >> W;
	cin >> S;
	queue<char> q;
	for (int i = 0; i < w; i++)
	{
		++alp1[getIndex(W[i])];
		++alp2[getIndex(S[i])];
		q.push(S[i]);
	}
	ans += cmp();
	for (int i = w; i < s; i++)
	{
		int p = q.front();
		--alp2[getIndex(p)];
		++alp2[getIndex(S[i])];
		q.pop();
		q.push(S[i]);
		ans += cmp();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1593