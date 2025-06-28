#include <iostream>
#include <algorithm>

using namespace std;

string B1, B2, ans = "";
int c = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> B1 >> B2;
	if (B1.size() > B2.size()) swap(B1, B2);
	int l = B1.size();
	for (int i = 0; i < B2.size() - l; i++)
		B1 = '0' + B1;
	for (int i = B2.size() - 1; i >= 0; i--)
	{
		int n = (B2[i] - '0') + (B1[i] - '0') + c;
		ans = (char)((n % 2) + '0') + ans;
		c = (n / 2);
	}
	if (c > 0) ans = '1' + ans;
	while (ans[0] == '0' && ans.size() > 1)
		ans = string(ans.begin() + 1, ans.end());
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1252