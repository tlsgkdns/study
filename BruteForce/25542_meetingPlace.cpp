#include <iostream>

using namespace std;

string ans = "", S[21];
int N, L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> S[i];
	string tmp = S[0];
	for (int i = 0; i < L; i++)
	{
		if (!ans.empty()) break;
		tmp = S[0];
		for (char ch = 'A'; ch <= 'Z'; ch++)
		{
			tmp[i] = ch;
			int idx = 1;
			for (idx = 1; idx < N; idx++)
			{
				int a = 0;
				for (int j = 0; j < L; j++)
					a += (tmp[j] != S[idx][j]);
				if (a > 1) break;
			}
			if (idx == N)
			{
				ans = tmp;
				break;
			}
		}
	}
	if (ans.empty()) cout << "CALL FRIEND\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25542