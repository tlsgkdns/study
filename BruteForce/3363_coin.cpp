#include <iostream>
#include <cstring>
using namespace std;
char op[3];
int l[3][4], r[3][4];
bool ans[13][2], nums[13];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(ans, true, sizeof(ans));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> l[i][j];
		cin >> op[i];
		for (int j = 0; j < 4; j++)
			cin >> r[i][j];
	}
	for (int i = 0; i < 3; i++)
	{
		if (op[i] == '=')
		{
			for (int j = 0; j < 4; j++)
			{
				ans[l[i][j]][0] = false;
				ans[l[i][j]][1] = false;
				ans[r[i][j]][0] = false;
				ans[r[i][j]][1] = false;
			}
		}
		else
		{

			memset(nums, false, sizeof(nums));
			for (int j = 0; j < 4; j++)
			{
				nums[l[i][j]] = true;
				nums[r[i][j]] = true;
			}
			for (int n = 1; n <= 12; n++)
				if (!nums[n])
				{
					ans[n][0] = false;
					ans[n][1] = false;
				}
			if (op[i] == '<')
			{
				for (int j = 0; j < 4; j++)
				{
					ans[l[i][j]][1] = false;
					ans[r[i][j]][0] = false;
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					ans[l[i][j]][0] = false;
					ans[r[i][j]][1] = false;
				}
			}
		}
	}
	int num = 0; char pm = '.';
	for (int n = 1; n <= 12; n++)
		for (int i = 0; i <= 1; i++)
		{
			if (num == -1) break;
			if (ans[n][i])
			{
				if (num != 0) num = -1;
				else
				{
					if (i == 0) pm = '-';
					else pm = '+';
					num = n;
				}
			}
		}
	if (num == 0) cout << "impossible\n";
	else if (num == -1) cout << "indefinite\n";
	else cout << num << pm << '\n';
}

// https://www.acmicpc.net/problem/3363