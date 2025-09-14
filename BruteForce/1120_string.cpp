#include <iostream>
#include <algorithm>

using namespace std;

string A, B;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B; ans = A.size();
	for (int i = 0; i <= B.size() - A.size(); i++)
	{
		string c = string(B.begin() + i, B.begin() + i + A.size());
		int cnt = 0;
		for (int idx = 0; idx < c.size(); idx++)
			cnt += (c[idx] != A[idx]);
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1120