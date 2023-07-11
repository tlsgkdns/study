#include <iostream>
#include <string>

using namespace std;

string str1, str2;
int dp[3003][3003];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> str1 >> str2;
	for (int i = 3; i <= str1.size(); i += 3)
		for (int j = 3; j <= str2.size(); j++)
			if (str1.substr(i - 3, 3) == str2.substr(j - 3, 3))
				dp[i][j] = dp[i - 3][j - 3] + 1;
			else
				dp[i][j] = max(dp[i - 3][j], dp[i][j - 3]);
	cout << dp[str1.size()][str2.size()] << '\n';
}

// https://www.acmicpc.net/problem/15482