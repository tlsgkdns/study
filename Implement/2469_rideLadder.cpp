#include <iostream>
#include <vector>
using namespace std;

vector<string> ladder;
string result, str, ans;
int N, K, idx;
void rideLadder()
{
	vector<int> s(N), e(N);

	for (int i = 0; i < N; i++)
	{
		int pos = i;
		for (int j = 0; j < idx; j++)
		{
			for (int d = -1; d <= 0; d++)
			{
				if (pos + d < 0 || pos + d >= N - 1) continue;
				if (ladder[j][pos + d] == '-')
				{
					pos = pos + d + ((d == -1) ? 0 : 1);
					break;
				}
			}
		}
		s[pos] = i;
	}
	s;
	for (int i = 0; i < N; i++)
	{
		int pos = i;
		for (int j = K - 1; j > idx; j--)
		{
			for (int d = -1; d <= 0; d++)
			{
				if (pos + d < 0 || pos + d >= N - 1) continue;
				if (ladder[j][pos + d] == '-')
				{
					pos = pos + d + ((d == -1) ? 0 : 1);
					break;
				}
			}
		}
		e[pos] = result[i] - 'A';
	}
	s, e;
	string tmp(N - 1, '*');
	for (int pos = 0; pos < N; pos++)
	{
		if (s[pos] == e[pos])
			tmp[pos] = '*';
		else if (pos < N - 1 && s[pos] == e[pos + 1])
			tmp[pos] = '-';
		else if (pos != 0 && s[pos - 1] == e[pos] && tmp[pos - 1] == '-')
			continue;
		else
		{
			ans = string(N - 1, 'x');
			return;
		}

	}
	ans = tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	ans = string(N, 'x');
	cin >> result;
	for (int i = 0; i < K; i++)
	{
		cin >> str;
		if (str[0] == '?') idx = i;
		ladder.push_back(str);
	}
	rideLadder();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2469