#include <iostream>
#include <unordered_map>

using namespace std;

string S, R[101];
int N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> R[i];
		R[i] += R[i];
	}
	for (int i = 0; i < N; i++)
	{
		int idx = 0;
		for (int j = 0; j < R[i].size(); j++)
			if (R[i][j] == S[idx])
			{
				++idx;
				if (idx == S.size())
				{
					ans++;
					break;
				}
			}
			else
			{
				if (idx > 0)
				{
					j--;
				}
				idx = 0;
			}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5555