#include <iostream>
#include <cctype>
using namespace std;

int N, tmp = 0;
string S;
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> S;
	for (int i = 0; i < N; i++)
	{
		if (isdigit(S[i])) tmp = tmp * 10 + (S[i] - '0');
		else
		{
			ans += tmp;
			tmp = 0;
		}
	}
	ans += tmp;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/8595