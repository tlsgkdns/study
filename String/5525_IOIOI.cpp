#include <iostream>
#include <string>
using namespace std;

int N, M, ans = 0;
string S;
char ch;
char getOpp(char ch)
{
	if (ch == 'I') return 'O';
	return 'I';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> S;
	char c = 'I';
	int cnt = 0, dst = 2 * N + 1;
	for (int i = 0; i < M; i++)
	{
		if (S[i] == c)
		{
			c = getOpp(c);
			cnt++;
			if (cnt == dst)
			{
				ans++;
				cnt -= 2;
			}
		}
		else
			cnt = (S[i] == 'I');
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5525