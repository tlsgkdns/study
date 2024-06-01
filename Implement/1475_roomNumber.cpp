#include <iostream>
#include <algorithm>

using namespace std;

string S;
int cnt[10], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		cnt[S[i] - '0']++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 6) continue;
		ans = max(ans, cnt[i]);
	}
	ans = max(ans, (cnt[6] + cnt[9] + 1) / 2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1475

/*
Six equals Nine
*/#include <iostream>
#include <algorithm>

using namespace std;

string S;
int cnt[10], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		cnt[S[i] - '0']++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 6) continue;
		ans = max(ans, cnt[i]);
	}
	ans = max(ans, (cnt[6] + cnt[9] + 1) / 2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1475