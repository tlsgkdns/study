#include <iostream>
#include <algorithm>
using namespace std;
string S, ans;
int cnt[2];
bool inc[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < (int)S.size(); i++) cnt[S[i] - '0']++;
	cnt[0] /= 2; cnt[1] /= 2;
	for (int i = 0; i < (int)S.size(); i++)
		if (cnt[1] > 0 && S[i] == '1')
		{
			cnt[1]--;
			inc[i] = true;
		}
	for (int i = (int)S.size() - 1; i >= 0; i--)
		if (cnt[0] > 0 && S[i] == '0')
		{
			cnt[0]--;
			inc[i] = true;
		}
	for (int i = 0; i < (int)S.size(); i++)
		if (!inc[i]) ans.push_back(S[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20310