#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string S1, S2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S1;
		S2 = S1;
		reverse(S1.begin(), S1.end());
		string num = to_string(stoi(S1) + stoi(S2));
		string ans = "YES\n";
		for (int i = 0; i < num.size() / 2; i++)
			if (num[i] != num[num.size() - i - 1])
			{
				ans = "NO\n";
				break;
			}
		cout << ans;
	}
}

// https://www.acmicpc.net/problem/3062