#include <iostream>
#include <unordered_map>

using namespace std;

string S;
unordered_map<string, int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
		for (int j = i + 1; j <= S.size(); j++)
		{
			string str(S.begin() + i, S.begin() + j);
			ans[str]++;
		}
	cout << ans.size() << '\n';
}

// https://www.acmicpc.net/problem/11478