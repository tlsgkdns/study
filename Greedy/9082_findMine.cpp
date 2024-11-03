#include <iostream>
#include <cstring>

using namespace std;

int N, T;
char ch;
int cnt[101], tmp1[101], tmp2[101];
bool mine[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(tmp1, 0, sizeof(tmp1));
		memset(tmp2, 0, sizeof(tmp2));
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> ch;
			cnt[i] = (ch - '0');
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> ch;
			mine[i] = (ch == '*');
			if (mine[i])
			{
				if (i > 0) --cnt[i - 1];
				--cnt[i];
				if (i < N - 1) --cnt[i + 1];
				++ans1; ++ans2;
			}
		}
		if (cnt[0] >= 1 && !mine[0])
		{
			tmp1[0]++; 
			tmp1[1]++;
			++ans1;
			for (int i = 1; i < N; i++)
			{
				if (tmp1[i - 1] + 1 == cnt[i - 1])
				{
					tmp1[i - 1]++;
					tmp1[i]++;
					if (i < N - 1) tmp1[i + 1]++;
					++ans1;
				}
			}
			for (int i = 0; i < N; i++)
			{

				if (tmp1[i] != cnt[i])
				{
					ans1 = 0;
					break;
				}
			}
		}
		for(int i = 1; i < N; i++)
			if (tmp2[i - 1] + 1 == cnt[i - 1])
			{
				tmp2[i - 1]++;
				tmp2[i]++;
				if (i < N - 1) tmp2[i + 1]++;
				++ans2;
			}
		for (int i = 0; i < N; i++)
		{
			if (tmp2[i] != cnt[i])
			{
				ans2 = 0;
				break;
			}
		}
		cout << max(ans1, ans2) << '\n';
	}
}

// https://www.acmicpc.net/problem/9082