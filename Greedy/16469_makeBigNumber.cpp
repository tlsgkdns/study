#include <iostream>
#include <algorithm>

using namespace std;
string ans = "";
int N;
string A[1001];
bool cmp(string& s1, string s2)
{
	return s1 + s2 > s2 + s1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N, cmp);
	for (int i = 0; i < N; i++) ans += A[i];
	if (ans[0] == '0') ans = "0";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16496