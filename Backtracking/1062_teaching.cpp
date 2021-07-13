#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int ALP = 26;

vector<string> words;
int N, K, ans = -1;
bool dp[1 << 21];
vector<int> basic = { 0, 2, 8, 13, 19 };

bool isOn(int num, int idx)
{
	return num & (1 << idx);
}

int alpToNum(char c)
{
	return c - 'a';
}
void solve(int sel, int d, int s)
{
	if (d == K)
	{
		int a = 0;
		for (int i = 0; i < N; i++)
		{
			bool f = true;
			for (char c : words[i])
				if (!isOn(sel, alpToNum(c)))
				{
					f = false;
					break;
				}
			if (f) a++;
		}
		ans = max(ans, a);
		return;
	}
	for (int i = s; i < ALP; i++)
	{
		if (isOn(sel, i)) continue;
		sel |= (1 << i);
		solve(sel, d + 1, i);
		sel &= ~(1 << i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	words.resize(N);
	for (int i = 0; i < N; i++)
		cin >> words[i];
	if (K < 5) ans = 0;
	else
	{
		int num = 0;
		for (int i = 0; i < 5; i++) num |= (1 << basic[i]);
		solve(num, 5, 0);
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1062