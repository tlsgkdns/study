#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
string S;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; getline(cin, S);
	for (int c = 1; c <= N; c++)
	{
		getline(cin, S);
		string w = "";
		S += ' ';
		vector<string> ans;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == ' ')
			{
				ans.push_back(w);
				w = "";
			}
			else
				w.push_back(S[i]);
		}
		cout << "Case " << "#" << c << ": ";
		for (int i = ans.size() - 1; i >= 0; i--)  cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/12605