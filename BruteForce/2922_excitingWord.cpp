#include <iostream>

using namespace std;
using ll = long long;
string S;
bool V[27];

ll solve(int idx, int c, int v, bool l)
{
	if (c == 3 || v == 3) return 0;
	if (idx == S.size()) return l;
	if (S[idx] == '_')
	{
		return (solve(idx + 1, c + 1, 0, l) * 20L)
			+ solve(idx + 1, c + 1, 0, true)
			+ (solve(idx + 1, 0, v + 1, l) * 5L);
	}
	else if (V[S[idx] - 'A'])
	{
		return solve(idx + 1, 0, v + 1, l);
	}
	else
	{
		return solve(idx + 1, c + 1, 0, l || (S[idx] == 'L'));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	V['O' - 'A'] = true; V['A' - 'A'] = true; V['E' - 'A'] = true;
	V['U' - 'A'] = true; V['I' - 'A'] = true;
	cout << solve(0, 0, 0, false) << '\n';
}

// https://www.acmicpc.net/problem/2922