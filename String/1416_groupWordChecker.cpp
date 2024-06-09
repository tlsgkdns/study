#include <iostream>
#include <cstring>
using namespace std;

int N, ans = 0;
string S;
bool A[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		memset(A, false, sizeof(A));
		char p = ';';
		bool f = true;
		for (int idx = 0; idx < S.size(); idx++)
		{
			if (p != S[idx])
			{
				p = S[idx];
				if (A[S[idx] - 'a'])
				{
					f = false;
					break;
				}
				A[S[idx] - 'a'] = true;
			}
		}
		ans += f;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1316