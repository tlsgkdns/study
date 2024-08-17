#include <iostream>
#include <cmath>

using namespace std;

string U, S, ans = "";
int N;
bool un = true;
int solve(int idx1, int idx2, bool j, string& s, bool d)
{
	if (idx2 == U.size() || (d && idx1 == (U.size() / 2)) || (!d && idx1 == (U.size() / 2 + 1)))
	{
		if (ans.empty()) ans = s;
		else if (ans != s)
			un = false;
		return 1;
	}
	if (U[idx1] == U[idx2])
	{
		s.push_back(U[idx1]);
		return solve(idx1 + 1, idx2 + 1, j, s, d);
	}
	if (!j)
	{
		if (d) return solve(idx1, idx2 + 1, true, s, d);
		return solve(idx1 + 1, idx2, true, s, d);
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> U;
	if (N % 2 == 0) cout << "NOT POSSIBLE\n";
	else
	{
		string s1 = "", s2 = "";
		int cnt = solve(0, (N / 2), false, s1, true) + solve(0, (N / 2) + 1, false, s2, false);
		if (cnt == 0) cout << "NOT POSSIBLE\n";
		else if (un) cout << ans << '\n';
		else cout << "NOT UNIQUE\n";
	}
}

// https://www.acmicpc.net/problem/10096