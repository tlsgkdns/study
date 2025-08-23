#include <iostream>
#include <string>

using namespace std;
bool P[100001];
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 2; i <= 100000; i++)
		if (!P[i])
			for (int j = i + i; j <= 100000; j += i)
				P[j] = true;
	while (true)
	{
		cin >> S;
		if (S == "0") break;
		int ans = 0;
		for (int i = 0; i < S.size(); i++)
			for (int j = i + 1; j <= S.size() && j - i < 7; j++)
			{
				int num = stoi(string(S.begin() + i, S.begin() + j));
				if (num > 100000) continue;
				if (!P[num]) ans = max(ans, num);
			}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/5636