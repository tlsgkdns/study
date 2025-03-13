#include <iostream>
#include <cstring>

using namespace std;
int N;
string S, str;
int cnt[27];
void solve()
{
	if (S.size() == str.size())
	{
		cout << str << '\n';
		return;
	}
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0) continue;
		cnt[i]--;
		str.push_back(i + 'a');
		solve();
		cnt[i]++;
		str.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		memset(cnt, 0, sizeof(cnt));
		cin >> S;
		for (int i = 0; i < S.size(); i++) cnt[S[i] - 'a']++;
		solve();
	}
}

// https://www.acmicpc.net/problem/6443