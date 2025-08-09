#include <iostream>
#include <algorithm>
using namespace std;
string dp[251];
int N;
string add(string& A, string& B)
{
	int u = 0;
	string ret = "";
	if (A.size() < B.size()) swap(A, B);
	int l = B.size();
	for (int i = 0; i < A.size() - l; i++) B = '0' + B;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		int n = A[i] - '0' + B[i] - '0' + u;
		u = n / 10;
		char ch = (n % 10) + '0';
		ret.push_back(ch);
	}
	if (u > 0) ret.push_back(u + '0');
	reverse(ret.begin(), ret.end());
	return ret;
}

string solve(int idx)
{
	if (idx == 0) return "1";
	if (idx == 1) return "1";
	if (idx == 2) return "3";
	string& ret = dp[idx];
	if (!ret.empty()) return ret;
	string l = solve(idx - 1), r = solve(idx - 2);
	r = add(r, r);
	ret = add(l, r);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (cin.eof()) break;
		cout << solve(N) << '\n';
	}
}

// https://www.acmicpc.net/problem/1793