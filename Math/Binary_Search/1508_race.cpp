#include <iostream>
#include <algorithm>
using namespace std;

string ans = "";
int N, M, K, L[51];

bool solve(int p)
{
	int ret = 0;
	for (int s = 0; s < K; s++)
	{
		int t = s, cnt = 1;
		for (int i = s + 1; i < K; i++)
		{
			if (L[i] - L[t] >= p)
			{
				t = i;
				++cnt;
			}
		}
		ret = max(cnt, ret);
	}
	return ret >= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) cin >> L[i];
	int l = 0, r = N + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) l = m;
		else r = m;
	}
	for (int s = 0; s < K; s++)
	{
		int cnt = 1, tmpS = s;
		string tmp = "";
		for (int i = 0; i < s; i++) tmp.push_back('0');
		tmp.push_back('1');
		for (int i = s + 1; i < K; i++)
		{
			if (L[i] - L[tmpS] >= l && cnt < M)
			{
				tmpS = i;
				++cnt;
				tmp.push_back('1');
			}
			else
				tmp.push_back('0');
		}
		if (cnt == M)
		{
			ans = tmp;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1508
