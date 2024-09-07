#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T, A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> S;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> A >> B;
			S.push_back({ A, B });
		}
		sort(S.begin(), S.end());
		int ans = 0, cnt = 1, m = S[0].second;
		for (int i = 1; i < N; i++)
		{
			if (m > S[i].second)
			{
				++cnt;
				m = S[i].second;
			}
		}
		cout << cnt << '\n';
	}
}

// https://www.acmicpc.net/problem/1946