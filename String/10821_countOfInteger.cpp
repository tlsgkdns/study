#include <iostream>
using namespace std;

string S, tmp = "";
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == ',')
		{
			tmp = "";
			++ans;
		}
		else
		{
			tmp.push_back(S[i]);
		}
	}
	if (tmp != "") ++ans;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10821