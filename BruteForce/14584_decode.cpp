#include <iostream>

using namespace std;

string C, ans, D[21];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> D[i];
	for (int t = 0; t < 26 && ans.empty(); t++)
	{
		string str = "";
		for (int idx = 0; idx < C.size(); idx++)
		{
			char ch = (((C[idx] - 'a') + t) % 26) + 'a';
			str.push_back(ch);
		}
		for (int idx = 0; idx < N; idx++)
		{
			if (str.find(D[idx]) == string::npos) continue;
			ans = str;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14584