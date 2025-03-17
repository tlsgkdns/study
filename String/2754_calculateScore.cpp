#include <iostream>

using namespace std;

string S;

void solve(string cmp, double result)
{
	if (S == cmp) cout << result << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(1);
	cin >> S;
	solve("A+", 4.3); solve("A0", 4.0); solve("A-", 3.7);
	solve("B+", 3.3); solve("B0", 3.0); solve("B-", 2.7);
	solve("C+", 2.3); solve("C0", 2.0); solve("C-", 1.7);
	solve("D+", 1.3); solve("D0", 1.0); solve("D-", 0.7);
	solve("F", 0.0);
}

// https://www.acmicpc.net/problem/2754