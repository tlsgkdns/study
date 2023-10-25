#include <iostream>

using namespace std;
string S;
bool f = false;
int C[3];
bool v[3][3][50][50][50];

void solve(int pp, int p, int a, int b, int c, string& s)
{
	if (f) return;
	if (a == 0 && b == 0 && c == 0)
	{
		cout << s << '\n';
		f = true;
		return;
	}
	if (v[pp][p][a][b][c]) return;
	v[pp][p][a][b][c] = true;
	if (a > 0)
	{
		s.push_back('A');
		solve(p, 0, a - 1, b, c, s);
		s.pop_back();
	}
	if (b > 0 && p != 1)
	{
		s.push_back('B');
		solve(p, 1, a, b - 1, c, s);
		s.pop_back();
	}
	if (c > 0 && pp != 2 && p != 2)
	{
		s.push_back('C');
		solve(p, 2, a, b, c - 1, s);
		s.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++) C[S[i] - 'A']++;
	string str = "";
	solve(0, 0, C[0], C[1], C[2], str);
	if (!f) cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/14238