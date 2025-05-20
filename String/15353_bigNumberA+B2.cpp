#include <iostream>
#include <algorithm>

using namespace std;
string A, B, ans = "";
int u = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	if (A.size() < B.size()) swap(A, B);
	int l = B.size();
	for (int i = 0; i < A.size() - l; i++) B = '0' + B;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		int n = A[i] - '0' + B[i] - '0' + u;
		u = n / 10;
		char ch = (n % 10) + '0';
		ans.push_back(ch);
	}
	if (u > 0) ans.push_back(u + '0');
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15353