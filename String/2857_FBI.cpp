#include <iostream>
#include <vector>
using namespace std;
string S;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	for (int i = 1; i <= 5; i++)
	{
		cin >> S;
		for (int j = 0; j < S.size() - 2; j++)
		{
			string w(S.begin() + j, S.begin() + j + 3);
			if (w == "FBI")
			{
				ans.push_back(i);
				break;
			}
		}
	}
	if (ans.empty()) cout << "HE GOT AWAY!\n";
	else
	{
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/2857