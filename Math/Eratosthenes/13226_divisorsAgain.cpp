#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, int>> input;
const int MAX = 10000001;
int factor[MAX];
int dp[MAX];
int L, U, T;

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	factor[0] = factor[1] = -1;
	for (int i = 2; i <= MAX; i++)
		factor[i] = i;
	for (int i = 2; i <= (int)sqrt(MAX); i++)
	{
		if (factor[i] == i)
			for (int j = i * i; j <= MAX; j += i)
				if (factor[j] == j)
					factor[j] = i;
	}
	for (int t = 0; t < T; t++)
	{
		cin >> L >> U;
		input.push_back({ L, U });
	}
	for (int t = 0; t < input.size(); t++)
	{
		int a = 1;
		for (int N = input[t].first; N <= input[t].second; N++)
		{
			vector<int> result;
			int tmp = N;
			if (dp[tmp] != -1)
			{
				a = max(a, dp[tmp]);
				continue;
			}
			int prev = 1, ct = 0, div = 1;
			while (tmp > 1)
			{
				if (factor[tmp] != prev)
				{
					div *= (ct + 1);
					prev = factor[tmp];
					ct = 0;
				}
				tmp /= factor[tmp];
				ct++;
			}
			div *= (ct + 1);
			dp[tmp] = div;
			a = max(a, div);
		}
		cout << a << '\n';
	}
}

// https://www.acmicpc.net/problem/13226