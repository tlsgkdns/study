#include <iostream>
using namespace std;

string S;
int ans1 = 0, ans2 = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size() - 2; i++)
	{
		string now(S.begin() + i, S.begin() + i + 3);
		ans1 += (now == "JOI");
		ans2 += (now == "IOI");
	}
	cout << ans1 << '\n' << ans2 << '\n';
}

// https://www.acmicpc.net/problem/5586