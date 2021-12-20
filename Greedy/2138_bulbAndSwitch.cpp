#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, ans = INF;
string str1, str2, cmp;

char oppo(char c)
{
	if (c == '0') return '1';
	else return '0';
}

void click(string& str, int idx)
{
	if (idx - 1 >= 0) str[idx - 1] = oppo(str[idx - 1]);
	if (idx + 1 < N) str[idx + 1] = oppo(str[idx + 1]);
	str[idx] = oppo(str[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> str1;
	cin >> cmp;
	str2 = str1;
	click(str2, 0);
	int c1 = 0, c2 = 1;
	for (int i = 1; i < N; i++)
	{
		if (str1[i - 1] != cmp[i - 1])
		{
			click(str1, i);
			c1++;
		}
		if (str2[i - 1] != cmp[i - 1])
		{
			click(str2, i);
			c2++;
		}
	}
	if (str1 == cmp) ans = c1;
	if (str2 == cmp) ans = min(ans, c2);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2138