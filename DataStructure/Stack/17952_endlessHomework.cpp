#include <iostream>
#include <stack>

using namespace std;

int N, A, T, C, nowt = 0, nows = 0, ans = 0;
stack<pair<int, int>> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C;
		if (C == 1)
		{
			cin >> A >> T;
			if (nowt > 0) S.push({ nowt, nows });
			nowt = T;
			nows = A;
		}
		if (nowt > 0)
		{
			if (--nowt == 0)
			{
				ans += nows;
				if (!S.empty())
				{
					nowt = S.top().first;
					nows = S.top().second;
					S.pop();
				}
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17952