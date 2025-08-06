#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int N, alp[26];
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	getline(cin, S);
	for (int i = 0; i < N; i++)
	{
		getline(cin, S);
		memset(alp, 0, sizeof(alp));
		for (int idx = 0; idx < S.size(); idx++)
		{
			if (S[idx] == ' ') continue;
			alp[S[idx] - 'a']++;
		}
		int t = 0, cnt = 0;
		for (int idx = 0; idx < 26; idx++)
		{
			if (alp[idx] > alp[t])
			{
				t = idx;
				cnt = 1;
			}
			else if (alp[idx] == alp[t])
			{
				++cnt;
			}
		}
		if (cnt > 1) cout << "?\n";
		else cout << (char)(t + 'a') << '\n';
	}
}

// https://www.acmicpc.net/problem/9046