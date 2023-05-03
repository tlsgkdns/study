#include <iostream>
#include <algorithm>
using namespace std;
string str[100001];
int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int ans = 100000001;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> str[i];
		if (N >= 48) cout << 0 << '\n';
		else
		{
			for (int i = 0; i < N; i++)
				for (int j = i + 1; j < N; j++)
					for (int k = j + 1; k < N; k++)
					{
						int a = 0;
						for (int idx = 0; idx < 4; idx++)
						{
							a += (str[i][idx] != str[j][idx]);
							a += (str[i][idx] != str[k][idx]);
							a += (str[j][idx] != str[k][idx]);
						}
						ans = min(ans, a);
					}
			cout << ans << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/20529