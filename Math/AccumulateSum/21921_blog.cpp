#include <iostream>

using namespace std;

int blog[250001], s[250001];
int N, X, ans = 0, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> X;
	for (int i = 1; i <= N; i++)
		cin >> blog[i];
	s[1] = blog[1];
	for (int i = 2; i <= N; i++)
		s[i] = blog[i] + s[i - 1];
	for (int i = 0; i <= N - X; i++)
	{
		int sub = s[i + X] - s[i];
		if (ans < sub)
		{
			ans = sub;
			cnt = 1;
		}
		else if (ans == sub)
			cnt++;
	}
	if (ans == 0) cout << "SAD\n";
	else cout << ans << '\n' << cnt << '\n';
}

// https://www.acmicpc.net/problem/21921