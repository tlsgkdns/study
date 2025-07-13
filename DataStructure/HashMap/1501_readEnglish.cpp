#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
string S;
unordered_map<string, int> dic;

string getWord(string& s)
{
	string ret = "";
	if (s.size() >= 2)
	{
		string tmp = string(s.begin() + 1, s.end() - 1);
		ret.push_back(s[0]); ret.push_back(s.back());
		sort(tmp.begin(), tmp.end());
		ret += tmp;
		return ret;
	}
	else
		return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		dic[getWord(S)]++;
	}
	cin >> M;
	getline(cin, S);
	while (M--)
	{
		getline(cin, S);
		while (S.back() == ' ') S.pop_back();
		S += ' ';
		string w = "";
		int ans = 1;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == ' ')
			{
				string f = getWord(w);
				ans *= dic[f];
				w.clear();
			}
			else
			{
				w.push_back(S[i]);
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1501