#include <iostream>

using namespace std;

string N, ans = "NO";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	if (N.size() > 1)
	{
		for (int i = 0; i < N.size(); i++)
		{
			long long a = 1, b = 1;
			for (int j = 0; j <= i; j++)
				a *= (N[j] - '0');
			for (int j = i + 1; j < N.size(); j++)
				b *= (N[j] - '0');
			if (a == b)
			{
				ans = "YES";
				break;
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1356