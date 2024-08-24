#include <iostream>
using namespace std;
string S;
bool on[1001];
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
		on[i] = (S[i] == 'Y');
	for (int i = 0; i < S.size(); i++)
	{
		if (on[i])
		{
			for (int idx = i; idx < S.size(); idx += (i + 1))
				on[idx] = !on[idx];
			++ans;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12927