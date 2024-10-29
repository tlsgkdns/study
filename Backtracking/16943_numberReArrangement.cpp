#include <iostream>
#include <string>

using namespace std;
using ll = long long;
string A, str = "";
ll B, ans = -1;
bool v[10];
void solve(int idx)
{
	if (idx == A.size())
	{
		ll num = stoll(str);
		if (num < B)
			ans = max(ans, num);
		return;
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (v[i] || (idx == 0 && A[i] == '0')) continue;
		v[i] = true;
		str.push_back(A[i]);
		solve(idx + 1);
		v[i] = false;
		str.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16943