#include <iostream>

using namespace std;

int T, N;
char C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		string ans = "";
		cin >> C;
		ans.push_back(C);
		for (int i = 1; i < N; i++)
		{
			cin >> C;
			if (ans.front() < C)
				ans.push_back(C);
			else
				ans = C + ans;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/13417